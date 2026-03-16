#pragma once

#include "window.h"


namespace engine
{

    class Application
    {
        public:
            Application();
            ~Application();

            // non copyable
            Application(const Application&) = delete;
            Application& operator=(const Application&) = delete;
            Application(Application&&) = delete;
            Application& operator=(Application&&) = delete;

            void run();

        private:
            void init();
            void shutdown();

            // game loop steps
            void process_input();
            void update(float dt);
            void render();
        
            // data
            Window m_window{};
            bool m_is_runing = false;
    };

}
