#pragma once

class QString;

namespace Scene
{
class ILabel
{
public:
    virtual void updateText(int value) = 0;
};
} // namespace Scene
