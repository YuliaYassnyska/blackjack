#pragma once

#include "enums/cardEnums/cardenums.h"
#include "icardfactory.h"

#include <QString>

namespace Model
{
class ICard;
}

namespace Scene
{
class ICard;
}

class CardFactory : public ICardFactory
{
public:
    CardFactory(Model::ICard *item, Theme theme);

    Scene::ICard *create() override;

private:
    Model::ICard *_item;
    Theme _theme;
};
