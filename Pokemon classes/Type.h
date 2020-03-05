//
// Created by felz on 04.03.2020.
//

#ifndef TEST_TYPE_H
#define TEST_TYPE_H

#include <iostream>
#include <unordered_map>
#include <string>

class Type {
public:
    explicit Type(std::string typ) {
        if(typ == "fire") {
            compare["fire"] = -1;
            compare["water"] = 1;
            compare["grass"] = -1;
        }
        else if (typ == "grass") {
            compare["fire"] = 1;
            compare["water"] = -1;
            compare["grass"] = -1;
        }
        else if (typ == "water") {
            compare["fire"] = -1;
            compare["water"] = -1;
            compare["grass"] = 1;
        }
    }
    std::unordered_map<std::string, int> compare;
};

#endif //TEST_TYPE_H
