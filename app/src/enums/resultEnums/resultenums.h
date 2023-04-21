#pragma once

#include <QString>

enum class Result
{
    WINNER,
    LOSER
};

enum class Game
{
    NEW,
    OVER
};

QString getResultText(Result result);
QString getGameText(Game game);
