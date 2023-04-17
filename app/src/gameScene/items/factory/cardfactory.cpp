#include "cardfactory.h"
#include "enums/cardEnums/cardenums.h"
#include "gameScene/items/cardItem/cardItem.h"
#include "model/items/cardItem/icard.h"

CardFactory::CardFactory(Model::ICard *item, Theme theme) : _item{ item }, _theme{ theme }
{
}

Scene::ICard *CardFactory::create()
{
    const QString startStr = ":/images/resources";

    QString cardPath = getCardPath(_item->card());
    QString suitPath = getSuitPath(_item->suit());
    QString themePath = startStr + getThemePath(_theme);

    return new Scene::CardItem(themePath, suitPath + cardPath, "/back_side.jpg");
}
