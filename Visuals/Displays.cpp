//
// Created by felz on 03.03.2020.
//

#include <iostream>

#include "../Players/Character.h"

#include "Displays.h"

void displayHealth(Character & player) {
    std::cout << player.getName() << "'s " << player.pkmn->getName() << ":\n";
    int p1HpPercentage = (player.pkmn->Health * 100) / (player.pkmn->stats->getBaseHp() * 10);
    std::cout << "[";
    for (int i = 0; i < 10; i++) {
        if(i < p1HpPercentage) {
            std::cout << "|";
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << "] " << player.pkmn->Health << "/" << player.pkmn->stats->getBaseHp() << std::endl;
}