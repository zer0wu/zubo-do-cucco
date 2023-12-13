#include "cubo.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
Cubo::Cubo()
{
}

Cubo::~Cubo()
{
    //dtor
}


void Cubo::resetCubo() {
    for (int x = 0; x != 8; x++) {
        for (int y = 0; y != 8; y++) {
            for (int z = 0; z != 8; z++) {
                matrix_led[x][y][z] = 0;
            }
        }
    }
}




void Cubo::ledOn(int x, int y, int z) {
matrix_led[x][y][z] = 1;

}

void Cubo::ledOff(int x, int y, int z) {
    matrix_led[x][y][z] = 0;

}

void Cubo::setCubo() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            for (int z = 0; z < 8; z++) {
                matrix_led[x][y][z] = 1;
            }
        }
    }
}

void Cubo::criaParticula( int x, int y) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        matrix_led[x][y][0] = 15;
    }
}

// Função para fazer as partículas "caírem" ao longo do eixo y
void Cubo::caiParticula () {



    const int permutacoes[24][4] = {
    {1, 2, 3, 4},
    {1, 2, 4, 3},
    {1, 3, 2, 4},
    {1, 3, 4, 2},
    {1, 4, 2, 3},
    {1, 4, 3, 2},
    {2, 1, 3, 4},
    {2, 1, 4, 3},
    {2, 3, 1, 4},
    {2, 3, 4, 1},
    {2, 4, 1, 3},
    {2, 4, 3, 1},
    {3, 1, 2, 4},
    {3, 1, 4, 2},
    {3, 2, 1, 4},
    {3, 2, 4, 1},
    {3, 4, 1, 2},
    {3, 4, 2, 1},
    {4, 1, 2, 3},
    {4, 1, 3, 2},
    {4, 2, 1, 3},
    {4, 2, 3, 1},
    {4, 3, 1, 2},
    {4, 3, 2, 1}
};
int a;
srand(time(NULL));
for (int x = 0; x < 8; x++) {
    for (int z = 0; z < 8; z++) {
        for (int y = 0; y < 8; y++) {
            if (matrix_led[x][y][z] == 15 && y < 7) {
                if(matrix_led[x+1][y][z] == 0){
                matrix_led[x+1][y][z] = 15;
                matrix_led[x][y][z] = 0;
            }
                else {
                a = rand()%24;
                int x = 0;
                for(int i = 0 ; i!= 1;x++){

                switch(permutacoes[a][x]){
                case 1:
                    if(matrix_led[x+1][y+1][z] == 0 && y < 7 && y > 0){
                        i = 1;
                        matrix_led[x][y][z] = 0;
                        matrix_led[x+1][y+1][z] = 1;
                        }
                        break;

                case 2:
                    if(matrix_led[x+1][y-1][z] == 0 && y < 7 && y > 0){
                        i = 1;
                        matrix_led[x][y][z] = 0;
                        matrix_led[x+1][y-1][z] = 1;
                        }
                        break;

                case 3:
                    if(matrix_led[x+1][y][z+1] == 0 && z < 7 && y > 0){
                        i = 1;
                        matrix_led[x][y][z] = 0;
                        matrix_led[x+1][y][z+1] = 1;
                        }
                        break;

                case 4:
                        if(matrix_led[x+1][y][z-1] == 0 && z < 7 && y > 0){
                        i = 1;
                        matrix_led[x][y][z] = 0;
                        matrix_led[x+1][y][z-1] = 1;
                        }
                        break;
                            }
                        }
                    }
                }
            }
        }
    }
}
