#pragma once

namespace Scene
{
class ICard;
}

class ICardFactory
{
public:
    virtual Scene::ICard *create() = 0;
};
