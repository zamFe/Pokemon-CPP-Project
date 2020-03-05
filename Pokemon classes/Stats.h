//
// Created by felz on 03.03.2020.
//

#ifndef TEST_STATS_H
#define TEST_STATS_H

#include <iostream>
#include <unordered_map>


class Stats {
public:
    Stats(double HP,
          double ATT,
          double DEF,
          double SPA,
          double SPD,
          double SPE) {
        baseHP = HP;
        baseATT = ATT;
        baseDEF = DEF;
        baseSPA = SPA;
        baseSPD = SPD;
        baseSPE = SPE;
        stages["HP"] = 0;
        stages["ATT"] = 0;
        stages["DEF"] = 0;
        stages["SPA"] = 0;
        stages["SPD"] = 0;
        stages["SPE"] = 0;
    }

    std::unordered_map<std::string, int> stages;

    double getBaseHp() const {
        return baseHP;
    }
    void setBaseHP(double baseHp) {
        baseHP = baseHp;
    }
    double getBaseATT() const {
        return baseATT;
    }
    void setBaseATT(double baseAt) {
        baseATT = baseAt;
    }
    double getBaseDEF() const {
        return baseDEF;
    }
    void setBaseDEF(double baseDe) {
        baseDEF = baseDe;
    }
    double getBaseSPA() const {
        return baseSPA;
    }
    void setBaseSPA(double baseSpa) {
        baseSPA = baseSpa;
    }
    double getBaseSPD() const {
        return baseSPD;
    }
    void setBaseSPD(double baseSpd) {
        baseSPD = baseSpd;
    }
    double getBaseSPE() const {
        return baseSPE;
    }
    void setBaseSPE(double baseSpe) {
        baseSPE = baseSpe;
    }
private:
    double baseHP;
    double baseATT;
    double baseDEF;
    double baseSPA;
    double baseSPD;
    double baseSPE;
};


#endif //TEST_STATS_H
