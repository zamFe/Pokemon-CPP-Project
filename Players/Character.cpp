//
// Created by felz on 03.03.2020.
//

#include "Character.h"

std::ostream &operator<<(std::ostream &os, Character * ch)
{
    os << ch->getName();
    return os;
}