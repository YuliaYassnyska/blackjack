#pragma once

#include <vector>

namespace Model
{
class ICard;
}

class ModelController
{
public:
    ModelController();

    std::vector<Model::ICard *> cards();

private:
    void createCards();

    std::vector<Model::ICard *> _cards;
};
