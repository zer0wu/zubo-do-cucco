#include <iostream>
#include "SerialCommunicator.h"
#include "windows.h"
#include <iomanip>

using namespace std;

int main() {
    const char* portName = "COM5";  // Change to your port name
    int baudRate = 115200;  // Adjust as needed

    SerialCommunicator communicator(portName, baudRate);

    if (communicator.openPort()) {
        cout << "Serial port opened successfully." << std::endl;

        // Test sending data
        uint8_t testMatrix[8][8][8] = {};  // Replace with your test data
        if (communicator.sendData(testMatrix)) {
            cout << "Data sent successfully." << std::endl;
        } else {
            cerr << "Failed to send data." << std::endl;
        }

        // Test receiving data
        uint8_t receivedData;
        if (communicator.receiveData(receivedData)) {
            cout << "Received data: 0x" << std::hex << static_cast<int>(receivedData) << endl;
        } else {
            cerr << "Failed to receive data." << endl;
        }

        // Test sending SNC command
        uint8_t i = 0;  // Adjust as needed
        communicator.sendSNC(i);
        cout << "SNC command sent successfully." << std::endl;

        communicator.closePort();
        cout << "Serial port closed." << std::endl;
    } else {
        cerr << "Failed to open the serial port." << std::endl;
    }

    return 0;
}
