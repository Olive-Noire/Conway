#include <SDL_timer.h>
#include <iostream>

#include "../Headers/Editor.hpp"

int main(int argc,char* argv[]) {

    for (std::uint8_t i(argc-1);i>0;i--) std::cout << argc-i << " - " << argv[argc-i] << std::endl;

    Editor conway;

    constexpr std::uint32_t frameDelay{1000/200}; // 200 ticks/fps
    std::uint32_t frameStart{0},frameTime{0};
    //unsigned int fps_start{SDL_GetTicks()},fps{0};

    std::cout << sizeof(conway) << std::endl;

    while (conway.run) {

        frameStart = SDL_GetTicks();

        conway.Update();
        conway.Render();

        /*
        fps++;
        if (SDL_GetTicks()>fps_start+1000) {

            std::cout << fps << "\n";
            fps = 0;
            fps_start = SDL_GetTicks();

        }
        */

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);

    }

    return 0;

}
