#include "engine/core/application.h"
#include <iostream>

int main()
{
    try 
    {
        engine::Application app;
        app.run();
    }
    catch (const std::exception& e)
    {
        // TraceLog(LOG_ERROR, "Application threw an exception: %s", e.what());
        // return 1;
        std::cerr << "[FATAL] Application threw an exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
