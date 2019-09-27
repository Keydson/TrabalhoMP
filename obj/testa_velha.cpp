// Copyright 2019 Keydson Estrela
#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/velha.hpp"

TEST_CASE("Verifica Jogo Indefinido"){
    WHEN("O jogo ainda não foi iniciado"){
        THEN("Nem X, nem O foram inseridos, deve retornar -1"){
            REQUIRE( checkGameVoid() == true);
        }
    }
    WHEN("Não existe um Empate ou Vencedor, mas o Jogo foi iniciado"){
        THEN("Jogo indefinido, deve retornar -1"){
            insereX(2,2);
            insereO(3,3);
            insereX(3,1);
            REQUIRE( checkGame() == -1);
            reiniciarJogo();
        }
    }
}
TEST_CASE(){
    WHEN("Jogo Finalizado"){
        THEN("Case empate, deve retornar 0"){
            insereX(2,2);
            insereO(1,3);
            insereX(3,2);
            insereO(1,2);
            insereX(1,1);
            insereO(3,3);
            insereX(2,3);
            insereO(2,1);
            insereX(3,1);
            REQUIRE(checkGame() == 0);
            reiniciarJogo();
        }
        THEN("X ganha, deve retornar 1"){
            insereX(1,1);
            insereO(1,2);
            insereX(2,2);
            insereO(1,3);
            insereX(3,3);
            REQUIRE(checkGame() == 1);
            reiniciarJogo();
        }
        THEN("O ganha, deve retornar 2"){
            insereX(1,3);
            insereO(1,1);
            insereX(1,2);
            insereO(2,2);
            insereX(3,1);
            insereO(3,3);
            REQUIRE(checkGame() == 2);
            reiniciarJogo();
        }
    }
}
TEST_CASE("Número da linha e/ou coluna") {
    WHEN("Caso o número da linha e/ou coluna seja maior que 3") {
        THEN("Deve ser retornado 0") {
            REQUIRE(verifNumColLin(4,6) == 0);
            REQUIRE(verifNumColLin(1235325,12389641) == 0);
        }
    }
    WHEN("Caso o número da linha e/ou coluna seja menor que 1") {
        THEN("Deve ser retornado 0") {
            REQUIRE(verifNumColLin(-1,-13) == 0);
            REQUIRE(verifNumColLin(0,0) == 0);
            REQUIRE(verifNumColLin(-27,0) == 0);
            REQUIRE(verifNumColLin(0,-1234) == 0);
        }
    }
    WHEN("0 < número da linha e/ou coluna < 4") {
        THEN("Deve ser retornado 1") {
            REQUIRE(verifNumColLin(1,1) == 1);
            REQUIRE(verifNumColLin(1,3) == 1);
            REQUIRE(verifNumColLin(3,1) == 1);
            REQUIRE(verifNumColLin(2,2) == 1);
        }
    }
}