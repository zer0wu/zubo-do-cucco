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
    void sendSNC(uint8_t i);

private:
    HANDLE hCom;
    const char* portName;
    int baudRate;
};
