//
// Created by felz on 31.01.2020.
//

#ifndef TEST_POKEMON_H
#define TEST_POKEMON_H

#include <array>
#include <iostream>

#include "Stats.h"
#include "Type.h"

class Pokemon {
public:
    Pokemon(std::string nm,
            std::string typ,
            std::string abi,
            std::array<std::string, 4>  moves,
            double HP,
            double AT,
            double DE,
            double SP_AT,
            double SP_DE,
            double SPD ) {
        name = nm;
        type = typ;
        typeMap = std::unique_ptr<Type> (new Type(typ));
        ability = abi;
        moveset = moves;
        Health = HP;
        stats = std::unique_ptr<Stats>(new Stats(HP, AT, DE, SP_AT, SP_DE, SPD));
    }
    std::array<std::string,4> moveset = {};
    double Health;
    std::unique_ptr<Stats> stats;

    //operator overloads
    void operator -=(int dmg) {
        Health -= dmg;
    };
    void operator +=(int hp) {
        Health += hp;
    };


    std::string getName() {
        return name;
    };
    std::string getType() {
        return type;
    }
    std::unordered_map<std::string, int> getTypeMap() {
        return typeMap->compare;
    }

    //operator overloads
    bool operator ==(int number) {
        return Health == number;
    }
    bool operator <=(int number) {
        return Health <= number;
    }
    bool operator >=(int number) {
        return Health >= number;
    }
    bool operator <(int number) {
        return Health < number;
    }
    bool operator >(int number) {
        return Health > number;
    }

    double getATT() const {
        double ATT = stats->getBaseATT();
        int stage = stats->stages["ATT"];
        return calculateModifier(ATT, stage);
    }
    double getDEF() const {
        double DEF = stats->getBaseDEF();
        int stage = stats->stages["DEF"];
        return calculateModifier(DEF, stage);
    }
    double getSPA() const {
        double SPA = stats->getBaseSPA();
        int stage = stats->stages["SPA"];
        return calculateModifier(SPA, stage);
    }
    double getSPD() const {
        double SPD = stats->getBaseSPD();
        int stage = stats->stages["SPD"];
        return calculateModifier(SPD, stage);
    }
    double getSPE() const {
        double SPE = stats->getBaseSPE();
        int stage = stats->stages["SPE"];
        return calculateModifier(SPE, stage);
    }
private:
    std::string ability;
    std::string name = "missingno";
    std::string type;
    std::unique_ptr<Type> typeMap;
    double calculateModifier(double stat, int stage) const {
        if(stage < 0) {
            stat = stat * ( 2.f / ((stage * (-1.f)) + 2.f));
        } else if (stage > 0) {
            stat = stat * ((stage + 2.f) / 2.f);
        }
        return stat;
    }
};

std::unique_ptr<Pokemon> pokemonSelect();

#endif //TEST_POKEMON_H
