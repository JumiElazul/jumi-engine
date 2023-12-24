#pragma once

namespace jumi
{

    class IGame
    {
    public:
        virtual ~IGame() = default;
        virtual void init() = 0;
        virtual void update(double delta_time) = 0;
        virtual void render() = 0;
        virtual void shutdown() = 0;
    };

}
