#include "window.h"
#include <raylib.h>
#include <stdexcept>

namespace engine
{

    Window::~Window()
    {
        close();
    }

    void Window::init(const WindowConfig& config)
    {
        if (m_is_initialized)
        {
            return;
        }
        m_config = config;
        
        // build raylib config flags
        unsigned int flags = 0;
        
        if (config.vsync) flags |= FLAG_VSYNC_HINT;
        if (config.resizable) flags |= FLAG_WINDOW_RESIZABLE;
        if (config.mssa_4x) flags |= FLAG_MSAA_4X_HINT;
        if (config.fullscreen) flags |= FLAG_FULLSCREEN_MODE;

        SetConfigFlags(flags);


        // open the window
        InitWindow(config.width, config.height, config.title.c_str());
        if (!IsWindowReady())
        {
            throw std::runtime_error("Failed to initialize the window");
        }
        SetTargetFPS(config.targetFPS);
        m_is_initialized = true;
    }
    
    void Window::close()
    {
        if (!m_is_initialized)
        {
            return;
        }
        CloseWindow();
        m_is_initialized = false;
        
    }
    
    void Window::begin_frame() const
    {
        BeginDrawing();
        ClearBackground(BLACK);
    }

    void Window::end_frame() const
    {
        EndDrawing();
    }



    //queries
    bool Window::should_close() const
    {
        return WindowShouldClose();
    }

    bool Window::is_ready() const
    {
        return m_is_initialized && IsWindowReady();
    }

    bool Window::is_fullscreen() const
    {
        return IsWindowFullscreen();
    }
    
    int Window::get_width() const
    {
        return GetScreenWidth();
    }

    int Window::get_height() const
    {
        return GetScreenHeight();
    }

    float Window::get_aspect_ratio() const
    {
        return (float)get_width() / (float)get_height();
    }

    double Window::get_time() const
    {
        return GetTime();
    }

    double Window::get_delta_time() const
    {
        return GetFrameTime();
    }
    
    int Window::get_fps() const
    {
        return GetFPS();
    }


    // setters
    void Window::toggle_fullscreen()
    {
        ToggleFullscreen();
    }

    void Window::start_target_fps(int fps)
    {
        m_config.targetFPS = fps;
        SetTargetFPS(fps);
    }
    
    void Window::set_title(const std::string& title)
    {
        m_config.title = title;
        SetWindowTitle(title.c_str());
    }

}



