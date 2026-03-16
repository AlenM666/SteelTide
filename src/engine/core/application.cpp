#include "application.h"

#include "raylib.h"

namespace engine
{

    Application::Application()
    {
        init();
        
        while (m_is_runing)
        {
            if (m_window.should_close())
            {
                m_is_runing = false;
                break;
            }
            
            const float dt = m_window.get_delta_time();
            process_input();
            update(dt);
            render();
        }
        shutdown();
    }

    void Application::init()
    {
        WindowConfig cfg;
        cfg.title = "Steel Tide";
        cfg.width = 1280;
        cfg.height = 720;
        cfg.targetFPS = 240;
        cfg.vsync = true;
        cfg.resizable = true;
        cfg.fullscreen = false;
        cfg.mssa_4x = true;

        m_window.init(cfg);
    }
}
