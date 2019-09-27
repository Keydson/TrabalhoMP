#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/velha.hpp"

TEST_CASE("Verifica Jogo Indefinido"){
    WHEN("O jogo ainda não foi iniciado"){
        THEN("checkGame() deve retornar -1"){
            REQUIRE( checkGame() == -1);
        }
    }
    WHEN("Não existe um Empate ou Vencedor, mas o Jogo foi iniciado"){
        THEN("checkGame() deve retornar -1"){
            insereX(1,1);
            insereO(2,2);
            REQUIRE( checkGame() == -1);
        }
    }
}