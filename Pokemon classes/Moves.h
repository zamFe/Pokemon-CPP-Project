//
// Created by felz on 04.02.2020.
//

#ifndef TEST_MOVES_H
#define TEST_MOVES_H

#include <unordered_map>

#include "Pokemon.h"

class Attack {
public:
    Attack() = default;
    Attack(std::string moveName,
            int powerPoints,
            int moveBasePower,
            int moveAccuracy,
            std::string typ,
            std::string primaryEffect,
            std::string secondaryEffect) {
        name = moveName;
        pp = powerPoints;
        basePower = moveBasePower;
        accuracy = moveAccuracy;
        type = typ;
        effect1 = primaryEffect;
        effect2 = secondaryEffect;
    }
    std::string getName() {
        return name;
    }

    int getPp() const {
        return pp;
    }

    void setPp(int pp) {
        Attack::pp = pp;
    }

    int getBasePower() const {
        return basePower;
    }

    int getAccuracy() const {
        return accuracy;
    }

    const std::string &getEffect1() const {
        return effect1;
    }

    const std::string &getEffect2() const {
        return effect2;
    }

    const std::string &getType() const {
        return type;
    }

private:
    std::string name;
    std::string type;
    int pp;
    int basePower;
    int accuracy;
    std::string effect1;
    std::string effect2;
};

std::unordered_map<std::string, Attack> getAttacks();

#endif //TEST_MOVES_H
