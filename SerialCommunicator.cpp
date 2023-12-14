
#include <iostream>
#include "SerialCommunicator.h"
#include "stdint.h"
#include "windows.h"
SerialCommunicator::SerialCommunicator(const char* port, int baud)
    : hCom(INVALID_HANDLE_VALUE), portName(port), baudRate(baud) {}

SerialCommunicator::~SerialCommunicator() {
    closePort();
}

bool SerialCommunicator::openPort() {
    hCom = CreateFile(
        portName,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hCom == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to open the serial port." << std::endl;
        return false;
    }

    DCB dcb;
    GetCommState(hCom, &dcb);
    dcb.BaudRate = baudRate;
    dcb.ByteSize = 8;
    dcb.StopBits = ONESTOPBIT;
    dcb.Parity = EVENPARITY;

    if (!SetCommState(hCom, &dcb)) {
        std::cerr << "Failed to set the communication parameters." << std::endl;
        return false;
    }

    return true;
}

void SerialCommunicator::closePort() {
    if (hCom != INVALID_HANDLE_VALUE) {
        CloseHandle(hCom);
        hCom = INVALID_HANDLE_VALUE;
    }
}

bool SerialCommunicator::sendData(const uint8_t matrix[8][8][8]) {
    if (hCom == INVALID_HANDLE_VALUE) {
        std::cerr << "Serial port not open." << std::endl;
        return false;
    }

    DWORD bytesWritten;
    if (!WriteFile(hCom, matrix, sizeof(uint8_t) * 8 * 8 * 8, &bytesWritten, NULL)) {
        std::cerr << "Failed to write data to the serial port." << std::endl;
        return false;
    }

    return true;
}
bool SerialCommunicator::receiveData(uint8_t& receivedData) {
    // Code to receive data from the serial port
    DWORD bytesRead;

    if (ReadFile(hCom, &receivedData, sizeof(receivedData), &bytesRead, NULL)) {
        return bytesRead == sizeof(receivedData);
    }

    return false;
}

void SerialCommunicator::sendSNC(uint8_t i) {

    uint8_t SNC[2] = {0xD3, 0x80+i};  // Adjust as needed
    WriteFile(hCom, SNC, sizeof(SNC), NULL, NULL);
}
