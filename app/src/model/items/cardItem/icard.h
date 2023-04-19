#pragma once

#include "enums/cardEnums/cardenums.h"

namespace Model
{
class ICard
{
public:
    virtual int value() const = 0;
    virtual Suit suit() const = 0;
    virtual Card card() const = 0;
    virtual unsigned id() const = 0;
    virtual void setOpen(bool isOpen) = 0;
    virtual bool isOpen() const = 0;
};
} // namespace Model
