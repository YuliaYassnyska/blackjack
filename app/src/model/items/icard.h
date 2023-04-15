#pragma once

#include "enums/cardEnums/cardenums.h"

namespace Model
{
class ICard
{
public:
    virtual int value() = 0;
    virtual Suit suit() = 0;
    virtual Card card() = 0;
};
} // namespace Model
