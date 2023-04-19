#pragma once

namespace Scene
{
class ICard
{
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void setPos(double x, double y) = 0;
    virtual unsigned modelId() const = 0;
    virtual bool isOpen() const = 0;
};
} // namespace Scene
