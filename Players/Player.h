//
// Created by felz on 03.03.2020.
//

#ifndef TEST_PLAYER_H
#define TEST_PLAYER_H

#include "Character.h"

class Player : public Character {
public:
    Attack moveSelect(std::array<std::string, 4> moveset, std::unordered_map<std::string, Attack> moveByName) override {
        std::cout << "\n====================\n"
                  << "1. " << moveset[0] << "\n"
                  << "2. " << moveset[1] << "\n"
                  << "3. " << moveset[2] << "\n"
                  << "4. " << moveset[3] << "\n"
                  << "====================\n"
                  << std::endl;

        std::string move;
        std::cin >> move;

        if(move == "1") {
            return moveByName[moveset[0]];
        } else if(move == "2") {
            return moveByName[moveset[1]];
        } else if(move == "3") {
            return moveByName[moveset[2]];
        } else if(move == "4") {
            return moveByName[moveset[3]];
        } else {
            std::transform(move.begin(), move.end(), move.begin(), [](unsigned char c){return std::tolower(c);});
            std::cout << std::string(50, '\n') << std::endl;
            return moveByName[move];
        }
    }

    int targetSelect(std::vector<std::shared_ptr<Character>> * players) override {
        int targetNr = 0;
        while(targetNr < 1 || targetNr > players->size() + 1) {
            std::cout <<  getName() << " select a target" << std::endl;
            for(int j = 0; j < players->size(); j++) {
                if((*players)[j]->pkmn->Health > 0) {
                    std::cout << j + 1 << ". " << (*players)[j]->getName() << std::endl;
                }
            }
            std::cin >> targetNr;
        }
        return targetNr;
    }
private:
};


#endif //TEST_PLAYER_H
