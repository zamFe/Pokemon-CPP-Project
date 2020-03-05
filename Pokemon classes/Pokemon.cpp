//
// Created by felz on 31.01.2020.
//

#include "Pokemon.h"

#include <iostream>
#include <string>
#include <string.h>

#include "Movesets.h"

//selects a pokemon
std::unique_ptr<Pokemon> pokemonSelect() {
    std::cout << "select a pokemon:\n"
              << "1. charmander\n"
              << "2. squirtle\n"
              << "3. bulbasaur"
              << std::endl;

    std::string x;
    std::cin >> x;
    std::transform(x.begin(), x.end(), x.begin(), [](unsigned char c){return std::tolower(c);});

    if(x == "charmander" || x == "1") {
        return std::unique_ptr<Pokemon> (new Pokemon (
                "Charmander",
                "fire",
                "blaze",
                fireMoves,
                39,
                52,
                43,
                60,
                50,
                65
        ));
    } else if (x == "squirtle" || x == "2") {
        return std::unique_ptr<Pokemon> ( new Pokemon(
                "Squritle",
                "water",
                "Torrent",
                waterMoves,
                44,
                48,
                65,
                50,
                64,
                43
        ));
    } else if (x == "bulbasaur" || x == "3") {
        return std::unique_ptr<Pokemon> (new Pokemon(
                "Bulbasaur",
                "grass",
                "Overgrow",
                grassMoves,
                45,
                49,
                49,
                65,
                65,
                45
        ));
    }
}