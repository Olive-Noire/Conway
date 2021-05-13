#include <SDL_timer.h>
#include <iostream>

#include "../Headers/Editor.hpp"

int main(int argc,char* argv[]) {

    for (unsigned int i(argc-1);i>0;i--) std::cout << argc-i << " - " << argv[(argc-i)] << std::endl;

    Editor::Init();

    constexpr std::uint32_t frameDelay(1000/200); // 200 ticks/fps
    std::uint32_t frameStart(0),frameTime(0);

    while (Editor::run) {

        frameStart = SDL_GetTicks();

        Editor::Update();
        Editor::Render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);

    }

    Editor::Quit();

    return 0;

}
