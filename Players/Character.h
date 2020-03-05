//
// Created by felz on 03.03.2020.
//

#ifndef TEST_CHARACTER_H
#define TEST_CHARACTER_H

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

#include "../Pokemon classes/Pokemon.h"
#include"../Pokemon classes/Moves.h"

class Character {
public:
    Character() {
        std::cout << "What is this trainers name?"
                  << std::endl;
        std::cin >> name;

        pkmn = pokemonSelect();
    }
    std::unique_ptr<Pokemon> pkmn;
    virtual Attack moveSelect(std::array<std::string, 4> moveset, std::unordered_map<std::string, Attack> moveByName) {
        std::cout << "override failed" << std::endl;
        return *(new Attack());
    }
    virtual int targetSelect(std::vector<std::shared_ptr<Character>> * players) {
        return 0;
    }

    std::string getName() {
        return name;
    }

    //operator overloads
    friend std::ostream &operator<<(std::ostream &os, Character * ch);

private:
    std::string name;
};


#endif //TEST_CHARACTER_H
