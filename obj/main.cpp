// Copyright 2019 Keydson Estrela
#include <stdio.h>
#include "../include/velha.hpp"

int main() {
    int k, C, L;
    while (1) {
        showGame();
        printf("\n\n1 - Inserir X\n"
                "2 - Inserir O\n"
                "0 - Reiniciar jogo\n"
                "9 - Sair\n"
                ">>");
        scanf("%d", &k);
        switch (k) {
            case 1:
                printf("\nDigite a Linha e a Coluna (C,L): ");
                scanf("%d,%d", &C, &L);
                insereX(L, C);
                break;
            case 2:
                printf("\nDigite a Linha e a Coluna (C,L): ");
                scanf("%d,%d", &C, &L);
                insereO(L, C);
                break;
            case 0:
                reiniciarJogo();
                break;
            case 9:
                return 0;
            default:
                printf("ERROR: Número inválido\n");
        }
        printf("\n%d\n\n", checkGame());
    }
    return 0;
}
