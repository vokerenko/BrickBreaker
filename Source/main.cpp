#include "stdafx.h"
#include "Engine.h"

int main()
{
    Engine engine;
    while (engine.isRunning())
    {
        engine.update();
        engine.render();
    }

    return EXIT_SUCCESS;
}