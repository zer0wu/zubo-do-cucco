#include "cubo.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
cubo::cubo()
{
}

cubo::~cubo()
{
    //dtor
}


void cubo::resetCubo() {
    for (int x = 0; x != 8; x++) {
        for (int y = 0; y != 8; y++) {
            for (int z = 0; z != 8; z++) {
                matrix_led[x][y][z] = 0;
            }
        }
    }
}


void cubo::ledOn(int x, int y, int z) {
matrix_led[x][y][z] = 15;

}

void cubo::ledOff(int x, int y, int z) {
    matrix_led[x][y][z] = 0;

}

void cubo::setCubo() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            for (int z = 0; z < 8; z++) {
                matrix_led[x][y][z] = 1;
            }
        }
    }
}

void cubo::criaParticula() {
    srand(time(NULL));
    int x = rand()%8;
    int y = rand()%8;
        matrix_led[0][x][y] = 15;
     x = rand()%8;
     y = rand()%8;
        matrix_led[0][x][y] = 15;
     x = rand()%8;
     y = rand()%8;
        matrix_led[0][x][y] = 15;

}

// Função para fazer as partículas "caírem" ao longo do eixo y
void cubo::caiParticula () {
int x,y,z;
for (z=7;z!=0;z--){
    for(y=0; y!= 8; y++){
        for(x=0;x!=8;x++){
            matrix_led[z][y][x] = matrix_led[z-1][y][x];
            matrix_led[z-1][y][x] = 0;
        }
    }
}

}

