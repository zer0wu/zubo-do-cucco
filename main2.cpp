#include "cubo.h"
#include <iostream>
#include "SerialCommunicator.h"
#include "windows.h"
void displayMatrix(const Cubo& cubo) {
    std::cout << "Current state of the cubo:" << std::endl;
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            for (int z = 0; z < 8; ++z) {
                std::cout << (cubo.matrix_led[x][y][z] ? "*" : "-") << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    Cubo cubo;
SerialCommunicator comunica("COM5", 115200);

comunica.openPort();

    // Test resetCubo
    std::cout << "Testing resetCubo..." << std::endl;
    cubo.resetCubo();
    comunica.sendData(cubo.matrix_led);
Sleep(1000);


    // Test setCubo
    std::cout << "Testing setCubo..." << std::endl;
    cubo.setCubo();
    comunica.sendSNC();
    comunica.sendData(cubo.matrix_led);
Sleep(1000);


    // Test ledOn and ledOff
    std::cout << "Testing ledOn and ledOff..." << std::endl;
    cubo.ledOn(2, 3, 4);

    comunica.sendSNC();
    comunica.sendData(cubo.matrix_led);
    Sleep(1000);


    cubo.ledOff(2, 3, 4);
    comunica.sendSNC();
    comunica.sendData(cubo.matrix_led);
    Sleep(1000);


cubo.resetCubo();
    // Test criaParticula
    std::cout << "Testing criaParticula..." << std::endl;


    cubo.criaParticula(1, 2);
    comunica.sendSNC();
    comunica.sendData(cubo.matrix_led);
    Sleep(1000);



    // Test caiParticula
    std::cout << "Testing caiParticula..." << std::endl;
    cubo.caiParticula();
    comunica.sendSNC();
    comunica.sendData(cubo.matrix_led);
    Sleep(1000);



    return 0;
}
