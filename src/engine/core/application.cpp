#include "application.h"

#include "raylib.h"

namespace engine
{
    Application::Application() = default;

    Application::~Application()
    {
        // shutdown() is normally called at the end of run().
        // The destructor is a safety net in case an exception unwinds the stack
        // before we get there — Window's own destructor handles CloseWindow(),
        // so nothing extra is needed here yet.
        
        
        // shutdown();
    }

    void Application::run()
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
        cfg.width = 800;
        cfg.height = 600;
        cfg.targetFPS = 240;
        cfg.vsync = false;
        cfg.resizable = true;
        cfg.fullscreen = true;
        cfg.mssa_4x = true;

        m_window.init(cfg);

        // ── Future systems go here, in dependency order ────────────────────────
        // m_audio.init();
        // m_asset_registry.load_all();
        // m_input.init();
        // m_scene_manager.push(std::make_unique<MainMenuScene>(...));
        

        m_is_runing = true;
    }

    void Application::shutdown()
    {
        m_is_runing = false;
        // ── Future systems go here, in reverse dependency order ─────────────────
        // m_scene_manager.clear();
        // m_input.shutdown();
        // m_asset_registry.unload_all();
        // m_audio.shutdown();

        m_window.close();
    }

    /* game loop */
    void Application::process_input()
    {
        
        // ── Hardwired global shortcuts ─────────────────────────────────────────
        // These are engine-level exits that live outside the scene/input system.
        // Once InputManager exists, scene-specific bindings move there instead.
        
        if (IsKeyPressed(KEY_ESCAPE))
        {
            m_is_runing = false;
            return;
        }

        if (IsKeyPressed(KEY_F11))
        {
            m_window.toggle_fullscreen();
        }

        // m_input.update();
        // m_scene_manager.current()->process_input(m_input);
    }

    
    void Application::update(float dt)
    {
        // m_scene_manager.current()->update(dt);
        (void)dt; // silence unused parameter warning until we have a scene manager
    }


    void Application::render()
    {
        m_window.begin_frame();
        
        // placeholder replace later
        // m_scene_manager.current()->render();
        DrawText("SteelTide - engine running", 20, 20, 20, WHITE);
        DrawText("Press F11 to toggle fullscreen  |  ESC to exit", 20, 50, 16, WHITE);
        DrawFPS(20, 80);

        m_window.end_frame();
    }

}
