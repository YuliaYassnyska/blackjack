#pragma once

namespace Scene
{
class ICard
{
public:
    virtual void open() = 0;
    virtual void close() = 0;
};
} // namespace Scene
