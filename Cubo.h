#ifndef CUBO_H
#define CUBO_H

#include "stdint.h"

class Cubo
{
public:
    Cubo();
    virtual ~Cubo();
    uint8_t matrix_led[8][8][8];    //matriz que define o estado de cada LED


protected:

    void resetCubo();           //zera o valor de todos os LEDs

    void ledOn(int x, int y, int z);  //liga um led especifico da matriz

    void ledOff(int x, int y, int z); //desliga um led especifico da matriz

    void setCubo();
//int sendcubo( matriz_led, int *controle);

    void criaParticula( int x, int y);

    void caiParticula ();


private:
};

#endif // CUBO_H

