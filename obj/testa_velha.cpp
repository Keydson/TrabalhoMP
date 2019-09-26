#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/velha.hpp"

TEST_CASE("Verifica Jogo Indefinido"){
    REQUIRE(checkGame()==-1);
}