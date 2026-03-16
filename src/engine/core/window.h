#pragma once 

#include "raylib.h"
#include <string>

namespace engine
{
    // WindowConfig
    //   keeping config separate from the class makes it easy to load
    //   these values from data/settings/game_config.json later.
    struct WindowConfig
    {
        std::string title = "Steel Tide";
        int width = 1280;
        int height = 720;
        int targetFPS = 240;
        bool vsync = true;
        bool resizable = true;
        bool fullscreen = true;
        bool mssa_4x = true;
    };

    //   Thin RAII wrapper around the Raylib window.
    //   owns the window lifetime — init() opens it, close() (or the destructor)
    //   shuts it down. Nothing else in the engine should call InitWindow /
    //   closeWindow directly.
    class Window
    {
        public:
            Window() = default;
            ~Window();
        
            // non copyable
            Window(const Window&) = delete;
            Window& operator=(const Window&) = delete;

            // Opens the OS window. Throws std::runtime_error on failure
            void init(const WindowConfig& config); 

            // Closes the OS window explicitly. Safe to call more than once.
            void close();             

            // call once at the start of ech frame
            void begin_frame() const;

            // call once et end of every frame, before swapping buffers
            void end_frame() const;

            
            // quireis
            bool should_close() const;
            bool is_ready() const;
            bool is_fullscreen() const;
            
            int get_width() const;
            int get_height() const;
            float get_aspect_ratio() const;
            
            double get_time() const; // used for animations and cooldowns
            double get_delta_time() const; // used for movment and physics
            float get_fps() const; // used for debugging and performance monitoring


            // setters
            void toggle_fullscreen();
            void start_target_fps(int fps);
            void set_title(const std::string& title);

            // raw config access
            const WindowConfig& get_config() const { return m_config; }

        private: 
            WindowConfig m_config{};
            bool m_is_initialized = false;
    };
} // namespace engine
