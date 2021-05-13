#include "../Headers/Editor.hpp"

#include <SDL.h>

#include "../Headers/Events.hpp"
#include "../Headers/GUI.hpp"

bool Editor::run,Editor::pause;
std::array<std::array<bool, 100>, 100> Editor::map;

Camera Editor::camera;
Commands Editor::commands;

SDL_Event Editor::event;
SDL_Renderer* Editor::renderer;
SDL_Window* Editor::window;

void Editor::Init(void) {

    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTS | SDL_INIT_VIDEO) != 0) return;

    Editor::window = SDL_CreateWindow("Conway",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Editor::width,Editor::height,SDL_WINDOW_SHOWN);
    Editor::renderer = SDL_CreateRenderer(Editor::window,0,SDL_RENDERER_ACCELERATED);

    Editor::pause = false;
    Editor::camera.zoom = Editor::height/Editor::map[1].size();

    Editor::run = true;

}

void Editor::Render(void) {

    SDL_RenderClear(Editor::renderer);

    for (std::size_t x{0};x<Editor::map.size();x++) for (std::size_t y{0};y<Editor::map[x].size();y++) {

        const SDL_Rect cell{(signed int)x*Editor::camera.zoom-Editor::camera.x,(signed int)y*Editor::camera.zoom-Editor::camera.y,(signed int)Editor::camera.zoom,(signed int)Editor::camera.zoom};

        if (Editor::map[x][y]) {
            
            SDL_SetRenderDrawColor(Editor::renderer, CELL_COLOR.r, CELL_COLOR.g, CELL_COLOR.b, CELL_COLOR.a);
            SDL_RenderFillRect(Editor::renderer, &cell);

        }

    }

    {

        const SDL_Rect border{-Editor::camera.x-1,-Editor::camera.y-1,(signed int)Editor::map.size()*Editor::camera.zoom+2,(signed int)Editor::map[1].size()*Editor::camera.zoom+2};
        SDL_SetRenderDrawColor(Editor::renderer, GRID_COLOR.r, GRID_COLOR.g, GRID_COLOR.b, GRID_COLOR.a);
        SDL_RenderDrawRect(Editor::renderer, &border);

        if (RENDER_GRID && Editor::camera.zoom>Editor::height/Editor::map[1].size()) {
        
            for (std::size_t i{0};i<Editor::map.size();i++) SDL_RenderDrawLine(Editor::renderer, -Editor::camera.x, -Editor::camera.y+i*Editor::camera.zoom, -Editor::camera.x+Editor::map.size()*Editor::camera.zoom, -Editor::camera.y+i*Editor::camera.zoom);
            for (std::size_t i{0};i<Editor::map[i].size();i++) SDL_RenderDrawLine(Editor::renderer, -Editor::camera.x+i*Editor::camera.zoom, -Editor::camera.y, -Editor::camera.x+i*Editor::camera.zoom, -Editor::camera.y+Editor::map[1].size()*Editor::camera.zoom);

        }

    }

    if (AABB(SDL_Rect{Editor::commands.mouse_pos[0],Editor::commands.mouse_pos[1],1,1},SDL_Rect{-Editor::camera.x-1,-Editor::camera.y-1,(signed int)Editor::map.size()*Editor::camera.zoom,(signed int)Editor::map[1].size()*Editor::camera.zoom})) {

        const SDL_Rect cursor{(Editor::commands.mouse_pos[0]+Editor::camera.x)/Editor::camera.zoom*Editor::camera.zoom-Editor::camera.x,(Editor::commands.mouse_pos[1]+Editor::camera.y)/Editor::camera.zoom*Editor::camera.zoom-Editor::camera.y,(signed int)Editor::camera.zoom,(signed int)Editor::camera.zoom};
        SDL_SetRenderDrawColor(Editor::renderer, CURSOR_COLOR.r, CURSOR_COLOR.g, CURSOR_COLOR.b, CURSOR_COLOR.a);
        SDL_RenderDrawRect(Editor::renderer, &cursor);

    }

    if (Editor::pause) {

        const SDL_Rect bar1{Editor::width-40,Editor::height-40,10,30},bar2{Editor::width-20,Editor::height-40,10,30};
        SDL_SetRenderDrawColor(Editor::renderer, PAUSE_COLOR.r, PAUSE_COLOR.g, PAUSE_COLOR.b, PAUSE_COLOR.a);
        SDL_RenderFillRect(Editor::renderer, &bar1);
        SDL_RenderFillRect(Editor::renderer, &bar2);

    }

    SDL_SetRenderDrawColor(Editor::renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
    SDL_RenderPresent(Editor::renderer);

}

void Editor::Update(void) {

    SDL_PollEvent(&Editor::event);
    if (Editor::event.type == SDL_QUIT || Editor::event.type == SDL_WINDOWEVENT_CLOSE) Editor::run = false;

    UpdateKeys(Editor::event);
    UpdateMouse(Editor::event);

    if (Editor::commands.mouse[SDL_BUTTON_LEFT] && AABB(SDL_Rect{Editor::commands.mouse_pos[0],Editor::commands.mouse_pos[1],1,1},SDL_Rect{-Editor::camera.x-1,-Editor::camera.y-1,(signed int)Editor::map.size()*Editor::camera.zoom+2,(signed int)Editor::map[1].size()*Editor::camera.zoom+2})) {

        Editor::map[(Editor::commands.mouse_pos[0]+Editor::camera.x)/Editor::camera.zoom][(Editor::commands.mouse_pos[1]+Editor::camera.y)/Editor::camera.zoom] = !Editor::map[(Editor::commands.mouse_pos[0]+Editor::camera.x)/Editor::camera.zoom][(Editor::commands.mouse_pos[1]+Editor::camera.y)/Editor::camera.zoom];
        Editor::commands.mouse[SDL_BUTTON_LEFT] = false;

    }

    if (Editor::commands.mouse[SDL_BUTTON_RIGHT]) {

        Editor::camera.x-=Editor::commands.mouse_pos[2]*Editor::commands.sensibility;
        Editor::camera.y-=Editor::commands.mouse_pos[3]*Editor::commands.sensibility;

    }

    if (Editor::commands.keys_once[Keys::SPACE]) Editor::pause=!Editor::pause;

    if (!Editor::commands.keys[Keys::ARROW_RIGHT]) Editor::camera.x-=5;
    if (!Editor::commands.keys[Keys::ARROW_LEFT]) Editor::camera.x+=5;
    if (!Editor::commands.keys[Keys::ARROW_UP]) Editor::camera.y+=5;
    if (!Editor::commands.keys[Keys::ARROW_DOWN]) Editor::camera.y-=5;

    if (Editor::camera.zoom+Editor::commands.wheel>0) {
        
        Editor::camera.zoom+=Editor::commands.wheel;
        Editor::camera.x-=Editor::commands.wheel*(Editor::width/2-Editor::commands.mouse_pos[0])/Editor::camera.zoom;
        Editor::camera.y-=Editor::commands.wheel*(Editor::height/2-Editor::commands.mouse_pos[1])/Editor::camera.zoom;

    }

    if (!Editor::pause || Editor::commands.keys[Keys::LETTER_N]) {

        if (Editor::commands.keys[Keys::LETTER_N]) Editor::commands.keys[Keys::LETTER_N] = false;

        std::array<std::array<bool, Editor::map[1].size()>, Editor::map.size()> next;

        for (std::size_t x{0};x<Editor::map.size();x++) for (std::size_t y{0};y<Editor::map[x].size();y++) {

            std::uint8_t adjacents{0};

            if (x < Editor::map.size() && Editor::map[x+1][y]) adjacents++;
            if (x > 0 && Editor::map[x-1][y]) adjacents++;
            if (y < Editor::map[1].size() && Editor::map[x][y+1]) adjacents++;
            if (y > 0 && Editor::map[x][y-1]) adjacents++;

            if (x < Editor::map.size() && y < Editor::map[1].size() && Editor::map[x+1][y+1]) adjacents++;
            if (x > 0 && y < Editor::map[1].size()-1 && Editor::map[x-1][y+1]) adjacents++;
            if (x < Editor::map.size()-1 && y > 0 && Editor::map[x+1][y-1]) adjacents++;
            if (x > 0 && y > 0 && Editor::map[x-1][y-1]) adjacents++;

            // Règles ;)
            next[x][y] = false;
            if (!Editor::map[x][y] && adjacents == 3) next[x][y] = true;
            if (Editor::map[x][y] && (adjacents == 2 || adjacents == 3)) next[x][y] = true;

        }

        Editor::map = next;

    }

    Editor::event = SDL_Event{};

}

void Editor::Quit(void) {

    SDL_DestroyRenderer(Editor::renderer);
    SDL_DestroyWindow(Editor::window);
    SDL_Quit();

}