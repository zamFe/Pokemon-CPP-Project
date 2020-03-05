//
// Created by felz on 29.01.2020.
//

//libraries
#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <array>
#include <vector>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <typeinfo>


//pokemon
#include "GameManager.h"
#include "Pokemon classes/Pokemon.h"
#include "Pokemon classes/Moves.h"

//player and AI
#include "Players/Player.h"
#include "Players/AI.h"

//visuals
#include "Visuals/Animations.h"
#include "Visuals/Displays.h"

std::vector<std::string> splitStringBySpace(std::string s) {
    std::vector<std::string> tokens;
    std::istringstream iss(s);
    std::copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::back_inserter(tokens)
            );
    return tokens;
}

//returns 0 for effective, -1 for less effective and 1 for super effective
int typeAdvantage(Attack move, Pokemon & defender) {
    std::string attType = move.getType();
    return defender.getTypeMap()[attType];
}

//calculates attack and deals appropriate damage to defender
void executeAttack(Character & attacker, Character & defender, Attack move) {


    //if move is damage based, deal damage
    if(move.getEffect1() == "dmg") {

        std::cout << &attacker << "'s " << attacker.pkmn->getName() << " used " << move.getName() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        //calculate damage
        int damage = ((((2*10/5)+2) * move.getBasePower() * (attacker.pkmn->getATT()/defender.pkmn->getDEF())) / 50) + 2;

        //apply type-advantage modifier
        switch(typeAdvantage(move, *defender.pkmn)) {
            case(0):
                break;
            case(1):
                damage = damage * 2;
                std::cout << "it's super effective!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
            case(-1):
                damage = damage * 0.5;
                std::cout << "it's not very effective..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
        }

        std::cout << move.getName() << " did " << damage << " damage!\n" << std::endl;
        *defender.pkmn -= damage;
        if(defender.pkmn->Health < 0) {defender.pkmn->Health = 0;}
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        return;
    }
    //else, calculate status changes
    else if (move.getEffect1().empty()) {

        std::cout << &attacker << "'s " << attacker.pkmn->getName() << " used " << move.getName() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::vector<std::string> statChanges = splitStringBySpace(move.getEffect2());

        //iterate through the stat changes and update accordingly
        for(auto it = statChanges.begin(); it < statChanges.end(); ++it) {
            std::string status = *it;

            std::string targetStr = status.substr(0,1);

            Character &target = (targetStr == "p") ? attacker : defender;

            std::string effect = status.substr(1,3);

            std::string modifier = status.substr(4,5);

            if(modifier.substr(1, 2) == "+") {
                target.pkmn->stats->stages[effect] += std::stoi(modifier.substr(0, 1));
                std::cout << target.getName() << "'s " << target.pkmn->getName() << "'s " << effect << " rose by "
                            << modifier.substr(0, 1) << " stage(s)\n" << std::endl;
            } else if (modifier.substr(1, 2) == "-") {
                target.pkmn->stats->stages[effect] -= std::stoi(modifier.substr(0, 1));
                std::cout << target.getName() << "'s " << target.pkmn->getName() << "'s " << effect << " fell by "
                          << modifier.substr(0, 1) << " stages(s)\n" << std::endl;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
}

void play() {

    //get list of attacks
    std::unordered_map<std::string, Attack> moveByName = getAttacks();

    //select AI or player mode

    int mode = 0;
    while(mode != 1 && mode != 2 && mode != 3) {
        std::cout << "Welcome to Pokemon CPP!\n"
                  << "please select a game mode:\n"
                  << "1. Player vs. Player (2 players)\n"
                  << "2. Player vs. Computer (1 player)\n"
                  << "3. Ultra stadium (Unlimited players)" << std::endl;
        std::cin >> mode;
    }

    clearScreen();

    std::vector<std::shared_ptr<Character>> players;

    if (mode == 1) {
        std::cout << "player1" << std::endl;
        players.push_back(std::shared_ptr<Player> (new Player()));
        clearScreen();
        std::cout << "player2" << std::endl;
        players.push_back(std::shared_ptr<Player> (new Player()));
    } else if (mode == 2) {
        std::cout << "player1" << std::endl;
        players.push_back(std::shared_ptr<Player> (new Player()));
        clearScreen();
        players.push_back(std::shared_ptr<AI> (new AI()));
    } else if (mode == 3) {
        std::cout << "input number of players: " << std::endl;
        int playerCount;
        std::cin >> playerCount;
        for(int i = 0; i < playerCount; i++) {
            players.push_back(std::shared_ptr<Player> (new Player()));
            clearScreen();
        }
    }

    clearScreen();
    //battleIntroSequence(); // commented out for debugging

    //start battle
    std::cout << "\nBattle!\n";
    std::cout << players[0]->getName();
    for(int i = 1; i < players.size(); i++) {
        std::cout << " vs. " << players[i]->getName();
    }
    std::cout << std::endl;

    int playersAlive = players.size();

    for(int k = 0; k < players.size(); k++) {
        displayHealth(*players[k]);
    }

    //loop until a player loses
    while(playersAlive > 1) {

        //TODO: get this to work!!!
        std::sort(players.begin(), players.end(), [](std::shared_ptr<Character> player1, std::shared_ptr<Character> player2){return player1->pkmn->getSPE() > player2->pkmn->getSPE();});

        for(int i = 0; i < players.size(); i++) {
            std::cout << players[i] << " select a move..." << std::endl;
            Attack move = players[i]->moveSelect(players[i]->pkmn->moveset, moveByName);

            clearScreen();

            int targetNr;

            //if two players, no need to select target
            if(playersAlive == 2) {
                if (i == 0) {
                    targetNr = 2;
                } else if (i == 1) {
                    targetNr = 1;
                }
            } else {
                //call targetselector if there are more than 1 opponent
                targetNr = players[i]->targetSelect(&players);
            }
            Character &target = *players[targetNr - 1];

            executeAttack(*players[i], target, move);

            for(int k = 0; k < players.size(); k++) {
                displayHealth(*players[k]);
            }

            //here pkmn is overloaded to use health in logic comparison operators
            if(*target.pkmn <= 0) {
                std::cout << "\n" << &target << "'s " << target.pkmn->getName() << " fainted" << std::endl;
                playersAlive -= 1;
                players.erase(players.begin() + targetNr - 1);
                if(playersAlive <= 0) {
                    break;
                }
            }
        }
    }

    std::cout << players[0] << " wins!" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

}