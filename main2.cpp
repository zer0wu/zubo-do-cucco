#include <iostream>
#include "SerialCommunicator.h"
#include "windows.h"
#include "Cubo.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
    const char* portName = "COM5";  // Change to your port name
    int baudRate = 115200;  // Adjust as needed
    Cubo cubo;
    SerialCommunicator communicator(portName, baudRate);

    if (communicator.openPort()) {
        cout << " Porta serial aberta ." << std::endl;
     uint8_t i = 0;
communicator.sendSNC(i);
        cout << "SNC enviado." << endl;
        // Test sending data

        // Test receiving data
 uint8_t receivedData;
        if (communicator.receiveData(receivedData)) {
            cout << "Retorno do SNC: 0x" << std::hex << static_cast<int>(receivedData) << endl;
        } else {
            cerr << "Failed to receive data." << endl;
        }


        uint8_t matrixToSend[8][8][8];
        for (int x = 0; x < 8; ++x) {
            for (int y = 0; y < 8; ++y) {
                for (int z = 0; z < 8; ++z) {
                    matrixToSend[x][y][z] = cubo.Getmatrizdata(x, y, z);
                }
            }
        }

        if (communicator.sendData(matrixToSend)) {
            cout << "Dados enviados." << endl;
        } else {
            cerr << "Falha no envio de dados" << endl;
        }


 uint8_t receivedData2;
        if (communicator.receiveData2(receivedData2)) {
            cout << "Retorno da matriz: 0x" << std::hex << static_cast<int>(receivedData2) << endl;
        } else {
            cerr << "Falha no envio nos cubos" << endl;
        }


        communicator.closePort();
        cout << "Porta Serial fechada" << endl;
    } else {
        cerr << "Falha em abrir na porta serial " << endl;
    }


   // communicator.ativa(i);
   // cout << "cubo ativado" << endl;



    return 0;
}
