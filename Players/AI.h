//
// Created by felz on 03.03.2020.
//

#ifndef TEST_AI_H
#define TEST_AI_H

#include "Character.h"

class AI : public Character {
public:
    Attack moveSelect(std::array<std::string, 4> moveset, std::unordered_map<std::string, Attack> moveByName) override {

        int x = std::rand() % 4 + 1;
        std::string move = std::to_string(x);

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
            std::cout << std::string(50, '\n');
            return moveByName[move];
        }
    }
    int targetSelect(std::vector<std::shared_ptr<Character>> * players) override {
        int targetNr = 0;
        while(targetNr < 1 || targetNr > players->size() + 1) {
            for(int j = 0; j < players->size(); j++) {
                if((*players)[j]->pkmn->Health > 0) {
                    if((*players)[j]->pkmn->getTypeMap()[pkmn->getType()] == -1) {
                        std::cout << "AI target: " << (*players)[j]->getName() << std::endl;
                    }
                }
            }
            std::cin >> targetNr;
        }
        return targetNr;
    }
private:

};


#endif //TEST_AI_H
