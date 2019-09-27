// Copyright 2019 Keydson Estrela
#include <stdio.h>
#include <stdbool.h>
#include "../include/velha.hpp"

int velha[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int contX = 0;
int contO = 0;
void showGame() {
    int i, j;
    int colum = 1;
    printf("  C 1 2 3\n"
           "L   -----\n");
    for (i = 0; i < 3; i++) {
        printf("%d|  ", colum);
        for (j = 0; j < 3; j++) {
            printf("%d ", velha[i][j]);
        }
        colum++;
        printf("\n");
    }
}
bool checkGameVoid() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (velha[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
int checkGame() {
    if (checkGameVoid() == true) {
       return -1;
    }
    // Possíveis vitórias de X
    if (velha[0][0] == 1 && velha[1][0] == 1 && velha[2][0] == 1) {
        reiniciarJogo();
        return 1;
    } else if (velha[0][1] == 1 && velha[1][1] == 1 && velha[2][1] == 1) {
        reiniciarJogo();
        return 1;
    } else if (velha[0][2] == 1 && velha[1][2] == 1 && velha[2][2] == 1) {
        reiniciarJogo();
        return 1;
    } else if (velha[0][0] == 1 && velha[0][1] == 1 && velha[0][2] == 1) {
        reiniciarJogo();
        return 1;
    } else if (velha[1][0] == 1 && velha[1][1] == 1 && velha[1][2] == 1) {
        reiniciarJogo();
        return 1;
    } else if (velha[2][0] == 1 && velha[2][1] == 1 && velha[2][2] == 1) {
        reiniciarJogo();
        return 1;
    } else if (velha[0][0] == 1 && velha[1][1] == 1 && velha[2][2] == 1) {
        reiniciarJogo();
        return 1;
    } else if (velha[2][0] == 1 && velha[1][1] == 1 && velha[0][2] == 1) {
        reiniciarJogo();
        return 1;
    }
    // Possíveis vitórias de O
    if (velha[0][0] == 2 && velha[1][0] == 2 && velha[2][0] == 2) {
        reiniciarJogo();
        return 2;
    } else if (velha[0][1] == 2 && velha[1][1] == 2 && velha[2][1] == 2) {
        reiniciarJogo();
        return 2;
    } else if (velha[0][2] == 2 && velha[1][2] == 2 && velha[2][2] == 2) {
        reiniciarJogo();
        return 2;
    } else if (velha[0][0] == 2 && velha[0][1] == 2 && velha[0][2] == 2) {
        reiniciarJogo();
        return 2;
    } else if (velha[1][0] == 2 && velha[1][1] == 2 && velha[1][2] == 2) {
        reiniciarJogo();
        return 2;
    } else if (velha[2][0] == 2 && velha[2][1] == 2 && velha[2][2] == 2) {
        reiniciarJogo();
        return 2;
    } else if (velha[0][0] == 2 && velha[1][1] == 2 && velha[2][2] == 2) {
        reiniciarJogo();
        return 2;
    } else if (velha[2][0] == 2 && velha[1][1] == 2 && velha[0][2] == 2) {
        reiniciarJogo();
        return 2;
    }
    // Verifica se o jogo é impossível
    if (contX-1 > contO || contO-1 > contX) {
        reiniciarJogo();
        return -2;
    }
    // Verifica se o jogo está empatado
    if (contX+contO == 9) {
        reiniciarJogo();
        return 0;
    }
    return -1;
}
void reiniciarJogo() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            velha[i][j] = 0;
        }
    }
    contX = 0;
    contO = 0;
}
void insereX(int L, int C) {
    if (velha[L-1][C-1] != 0) {  // Garante que X ou O seja sobrescrito
        printf("\n\nERROR: Esta posicao ja foi preenchida\n\n");
        checkGame();
    } else {
        velha[L-1][C-1] = 1;
        contX++;
    }
}
void insereO(int L, int C) {
    if (velha[L-1][C-1] != 0) {  // Garante que X ou O seja sobrescrito
        printf("\n\nERROR: Esta posicao ja foi preenchida\n\n");
        checkGame();
    } else {
        velha[L-1][C-1] = 2;
        contO++;
    }
}
int verifNumColLin(int L, int C) {
    if (L < 1 || L > 3 || C < 1 || C > 3) {
        printf("\n\nERROR: Posicao inválida\n\n");
        return 0;
    } else {
        return 1;
        }
}
