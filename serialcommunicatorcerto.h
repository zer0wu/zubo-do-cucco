#pragma once
#include "stdint.h"
#include <windows.h>

class SerialCommunicator {
public:
    SerialCommunicator(const char* portName, int baudRate);
    ~SerialCommunicator();

    bool openPort();
    void closePort();
    bool sendData(const uint8_t matrix[8][8][8]);
    bool receiveData(uint8_t& receivedData);
    bool receiveData2(uint8_t& receivedData2);
    bool receiveData3(uint8_t& receivedData3);
    void sendSNC();
    void ativa();
    void cleanse();
private:
    HANDLE hCom;
    const char* portName;
    int baudRate;
};
