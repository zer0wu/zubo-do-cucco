#include <iostream>
#include "SerialCommunicator.h"
#include "windows.h"
#include "Cubo.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {

    const char* portName = "COM6";  // nome da porta
    int baudRate = 115200;
    cubo cubo;
    uint8_t receivedData;
    uint8_t receivedData2;
    uint8_t receivedData3;
    SerialCommunicator communicator(portName, baudRate);

    if (communicator.openPort()) {
        cout << " Porta serial aberta ." << std::endl;

cubo.resetCubo();
while(1){



do{

communicator.sendSNC();
        cout << "SNC enviado." << endl;

Sleep(200);

        if (communicator.receiveData(receivedData)) {
            cout << "Retorno do SNC: 0x" << std::hex << static_cast<int>(receivedData) << endl;
        } else {
            cerr << "Failed to receive data." << endl;
        }
}while(!0x4D);

do{
        if (communicator.sendData(cubo.matrix_led)) {
            cout << "Dados enviados." << endl;
        } else {
            cerr << "Falha no envio de dados" << endl;
        }



        if (communicator.receiveData2(receivedData2)) {
            cout << "Retorno da matriz: 0x" << std::hex << static_cast<int>(receivedData2) << endl;
        } else {
            cerr << "Falha no envio nos cubos" << endl;
        }
}while(!0x41);


    communicator.ativa();

        if (communicator.receiveData3(receivedData3)) {
            cout << "Bit de confirmacao: 0x" << std::hex << static_cast<int>(receivedData3) << endl;
        } else {
            cerr << "Falha no envio nos cubos" << endl;
        }

    cout << "cubo ativado\n" << endl;

Sleep(100);
 cubo.caiParticula();

    cubo.criaParticula();

}

    communicator.closePort();
        cout << "Porta Serial fechada" << endl;
    } else {
        cerr << "Falha em abrir na porta serial " << endl;
    }



    return 0;
}
