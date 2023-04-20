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
