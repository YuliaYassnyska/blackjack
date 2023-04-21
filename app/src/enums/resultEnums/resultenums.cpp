#include "resultenums.h"

QString getResultText(Result result)
{
    switch (result)
    {
    case Result::LOSER:
        return QStringLiteral("You lose!");
    case Result::WINNER:
        return QStringLiteral("You win!!!");
    }

    return QLatin1String();
}

QString getGameText(Game game)
{
    switch (game)
    {
    case Game::NEW:
        return QStringLiteral("Start your game!");
    case Game::OVER:
        return QStringLiteral("Game over :(");
    }

    return QLatin1String();
}
