//
// Created by felz on 03.03.2020.
//

#include "Moves.h"

#include <iostream>
#include <string>
#include <string.h>

std::unordered_map<std::string, Attack> getAttacks() {
    std::unordered_map<std::string, Attack> moveByName;
    moveByName["scratch"] = *new Attack("scratch", 35, 40, 100, "normal", "dmg", "");
    moveByName["tackle"] = *new Attack("tackle", 35, 40, 100, "normal", "dmg", "");

    moveByName["growl"] = *new Attack("growl", 20, 0, 0, "normal", "","eATT1- ");
    moveByName["smokescreen"] = *new Attack("smokescreen", 20, 0, 100, "normal", "", "eACC1- ");
    moveByName["tail whip"] = *new Attack("tail whip", 30, 0, 100, "normal", "", "eDEF1- ");
    moveByName["withdraw"] = *new Attack("withdraw", 40, 0, 0, "water", "", "pDEF1+ ");
    moveByName["growth"] = *new Attack("growth", 20, 0, 101, "normal", "", "pATT1+ pSPA1+ ");


    moveByName["ember"] = *new Attack("ember", 25, 40, 100, "fire", "dmg", "burn10% ");
    moveByName["water gun"] = *new Attack("water gun", 25, 40, 100, "water", "dmg", "");
    moveByName["vine whip"] = *new Attack("vine whip", 25, 40, 100, "grass", "dmg", "");
    return moveByName;
}