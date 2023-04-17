#include "modelcontroller.h"
#include "enums/cardEnums/cardenums.h"
#include "model/items/cardItem/carditem.h"

ModelController::ModelController()
{
    createCards();
}

std::vector<Model::ICard *> ModelController::cards()
{
    return _cards;
}

void ModelController::createCards()
{
    for (unsigned suit = static_cast<unsigned>(Suit::MIN_VALUE);
         suit <= static_cast<unsigned>(Suit::MAX_VALUE); ++suit)
    {
        for (unsigned card = static_cast<unsigned>(Card::MIN_VALUE);
             card <= static_cast<unsigned>(Card::MAX_VALUE); ++card)
        {
            _cards.push_back(new Model::CardItem(Suit(suit), Card(card)));
        }
    }
}
