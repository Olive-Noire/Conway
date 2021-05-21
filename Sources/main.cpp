#include <SDL_timer.h>
#include <iostream>

#include "../Headers/Editor.hpp"

int main(int argc,char* argv[]) {

    for (int i{argc-1};i>0;i--) std::cout << argc-i << " - " << argv[argc-i] << std::endl;

    Editor conway;

    constexpr std::uint32_t frameDelay{1000/200}; // 200 ticks/fps

    std::uint32_t frameStart{0};
    std::uint32_t frameTime{0};

    while (conway.run) {

        frameStart = SDL_GetTicks();

        conway.Update();
        conway.Render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);

    }

    return 0;

}

// g++ -m32 "./Code/Sources/*.cpp" -o "./bin/Conway" -s -std=c++17 -I "./include/" -L "./lib/" -lSDL2main -lSDL2 -Wall -Wextra -pedantic-errors -DNDEBUG