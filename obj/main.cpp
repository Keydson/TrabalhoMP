// Copyright 2019 Keydson Estrela
#include <stdio.h>
#include "../include/velha.hpp"

int main() {
    int k, C, L;
    while (1) {
        showGame();  // Imprime a matriz a cada loop
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
                if (verifNumColLin(L, C) == 0) {
                    break;  // Se o índice seja inválido, X não é inserido
                }
                insereX(L, C);  // Insere X no índice informado
                break;
            case 2:
                printf("\nDigite a Linha e a Coluna (C,L): ");
                scanf("%d,%d", &C, &L);
                if (verifNumColLin(L, C) == 0) {
                    break;  // Se o índice seja inválido, O não é inserido
                }
                insereO(L, C);  // Insere O no índice informado
                break;
            case 0:
                reiniciarJogo();  // Reiniciar o jogo, cao o usuário desejar
                break;
            case 9:
                return 0;
            default:
                // Retorna mensagem de erro caso o valor seja inválido
                printf("ERROR: Número inválido\n");
        }
        printf("\n%d\n\n", checkGame());  // Imprime o status da partida
    }
    return 0;
}
