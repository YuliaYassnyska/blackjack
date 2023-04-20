#pragma once

#include <QString>

enum class Result {
    WINNER,
    LOSER
};

QString getResultText(Result result);
