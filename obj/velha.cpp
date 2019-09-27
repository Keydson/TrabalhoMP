// Copyright 2019 Keydson Estrela
#include <stdio.h>
#include <stdbool.h>
#include "../include/velha.hpp"

int velha[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
void showGame() {
    int i, j;
    int colum = 1;
    printf("  L 1 2 3\n"
           "C   -----\n");
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
    return -1;
}
