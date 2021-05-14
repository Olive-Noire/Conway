#include "../Headers/Editor.hpp"

#include <SDL.h>
#include <iostream>

#include "../Headers/Events.hpp"
#include "../Headers/GUI.hpp"

Editor::Editor() {

    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTS | SDL_INIT_VIDEO) != 0) return;

    this->window = SDL_CreateWindow("Conway",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Screen::width,Screen::height,SDL_WindowFlags::SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(this->window,0,SDL_RendererFlags::SDL_RENDERER_ACCELERATED);

    this->pause = false;
    this->camera.zoom = Screen::height/this->map.height;

    for (std::uint8_t i{0};i<7;i++) commands.mouse[i] = commands.mouse_once[i] = false; 
    for (std::uint8_t i{0};i<240;i++) commands.keys[i] = commands.keys_once[i] = false; 

    this->run = true;

}

void Editor::Render() const noexcept {

    SDL_RenderClear(this->renderer);

    for (std::size_t x{0};x<this->map.width;x++) for (std::size_t y{0};y<this->map.height;y++) {

        const SDL_Rect cell{(signed int)x*this->camera.zoom-this->camera.x,(signed int)y*this->camera.zoom-this->camera.y,(signed int)this->camera.zoom,(signed int)this->camera.zoom};

        if (this->map.surface[x][y]) {
            
            SDL_SetRenderDrawColor(this->renderer, CELL_COLOR.r, CELL_COLOR.g, CELL_COLOR.b, CELL_COLOR.a);
            SDL_RenderFillRect(this->renderer, &cell);

        }

    }

    {

        const SDL_Rect border{-this->camera.x-1,-this->camera.y-1,(signed int)this->map.width*this->camera.zoom+2,(signed int)this->map.height*this->camera.zoom+2};
        SDL_SetRenderDrawColor(this->renderer, GRID_COLOR.r, GRID_COLOR.g, GRID_COLOR.b, GRID_COLOR.a);
        SDL_RenderDrawRect(this->renderer, &border);

        if (RENDER_GRID && this->camera.zoom>ZOOM_VIEW_GRID && this->camera.zoom>1) {
        
            for (std::size_t i{0};i<this->map.width;i++) SDL_RenderDrawLine(this->renderer, -this->camera.x, -this->camera.y+i*this->camera.zoom, -this->camera.x+this->map.width*this->camera.zoom, -this->camera.y+i*this->camera.zoom);
            for (std::size_t i{0};i<this->map.height;i++) SDL_RenderDrawLine(this->renderer, -this->camera.x+i*this->camera.zoom, -this->camera.y, -this->camera.x+i*this->camera.zoom, -this->camera.y+this->map.height*this->camera.zoom);

        }

    }

    if (AABB(SDL_Rect{this->commands.mouse_pos[0],this->commands.mouse_pos[1],1,1},SDL_Rect{-this->camera.x-1,-this->camera.y-1,(signed int)this->map.width*this->camera.zoom,(signed int)this->map.height*this->camera.zoom})) {

        const SDL_Rect cursor{(this->commands.mouse_pos[0]+this->camera.x)/this->camera.zoom*this->camera.zoom-this->camera.x,(this->commands.mouse_pos[1]+this->camera.y)/this->camera.zoom*this->camera.zoom-this->camera.y,(signed int)this->camera.zoom,(signed int)this->camera.zoom};
        SDL_SetRenderDrawColor(this->renderer, CURSOR_COLOR.r, CURSOR_COLOR.g, CURSOR_COLOR.b, CURSOR_COLOR.a);
        SDL_RenderDrawRect(this->renderer, &cursor);

    }

    if (pause) {

        const SDL_Rect bar1{Screen::width-40,Screen::height-40,10,30},bar2{Screen::width-20,Screen::height-40,10,30};
        SDL_SetRenderDrawColor(this->renderer, PAUSE_COLOR.r, PAUSE_COLOR.g, PAUSE_COLOR.b, PAUSE_COLOR.a);
        SDL_RenderFillRect(this->renderer, &bar1);
        SDL_RenderFillRect(this->renderer, &bar2);

    }

    SDL_SetRenderDrawColor(this->renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
    SDL_RenderPresent(this->renderer);

}

void Editor::Update() noexcept {

    SDL_PollEvent(&this->event);
    if (this->event.type == SDL_EventType::SDL_QUIT || this->event.type == SDL_WindowEventID::SDL_WINDOWEVENT_CLOSE) this->run = false;

    UpdateCommandsKeys(this->event, this->commands);
    UpdateCommandsMouse(this->event, this->commands);

    // Met/enlève une cellule
    if (this->commands.mouse_once[SDL_BUTTON_LEFT] && AABB(SDL_Rect{this->commands.mouse_pos[0],this->commands.mouse_pos[1],1,1},SDL_Rect{-this->camera.x-1,-this->camera.y-1,(signed int)this->map.width*this->camera.zoom+2,(signed int)this->map.height*this->camera.zoom+2})) {

        this->map.surface[(this->commands.mouse_pos[0]+this->camera.x)/this->camera.zoom][(this->commands.mouse_pos[1]+this->camera.y)/this->camera.zoom] = !this->map.surface[(this->commands.mouse_pos[0]+this->camera.x)/this->camera.zoom][(this->commands.mouse_pos[1]+this->camera.y)/this->camera.zoom];

    }

    // Déplace la caméra à l'aide de la souris
    if (this->commands.mouse[SDL_BUTTON_RIGHT]) {

        this->camera.x-=this->commands.mouse_pos[2]*this->commands.sensibility;
        this->camera.y-=this->commands.mouse_pos[3]*this->commands.sensibility;

    }

    // Met/enlève pause
    if (this->commands.keys_once[Keys::SPACE]) this->pause=!this->pause;

    // Déplace la caméra à l'aide des flècehs
    if (!this->commands.keys[Keys::ARROW_RIGHT]) this->camera.x-=5;
    if (!this->commands.keys[Keys::ARROW_LEFT]) this->camera.x+=5;
    if (!this->commands.keys[Keys::ARROW_UP]) this->camera.y+=5;
    if (!this->commands.keys[Keys::ARROW_DOWN]) this->camera.y-=5;

    // Clear la Map
    if (this->commands.keys_once[std::uint16_t(Keys::LETTER_C)]) this->map.Clear();

    // CTRL + Keys
    if (this->commands.keys[Keys::LCTRL] || this->commands.keys[Keys::RCTRL]) {

        // Zoom CTRL + PLUS
        if (this->commands.keys_once[Keys::PLUS] || this->commands.keys_once[Keys::KP_PLUS]) {
            
            this->camera.zoom++;
            this->camera.x-=(Screen::width/2-this->commands.mouse_pos[0])/this->camera.zoom;
            this->camera.y-=(Screen::height/2-this->commands.mouse_pos[1])/this->camera.zoom;

        }

        // Dezoom CTRL + MINUS
        if ((this->commands.keys_once[Keys::MINUS] || this->commands.keys_once[Keys::KP_MINUS]) && this->camera.zoom>1) {
            
            this->camera.zoom--;
            this->camera.x-=(Screen::width/2-this->commands.mouse_pos[0])/this->camera.zoom;
            this->camera.y-=(Screen::height/2-this->commands.mouse_pos[1])/this->camera.zoom;

        }

    }

    // Zoom/Dezoom avec le scroll
    if (this->camera.zoom+this->commands.wheel>0) {
        
        this->camera.zoom+=this->commands.wheel;
        this->camera.x-=this->commands.wheel*(Screen::width/2-this->commands.mouse_pos[0])/this->camera.zoom;
        this->camera.y-=this->commands.wheel*(Screen::height/2-this->commands.mouse_pos[1])/this->camera.zoom;

    }

    // Si il n'y a pas pause ou si la touche "n" (next) est préssé alors la map passe un tick
    if (!this->pause || this->commands.keys_once[Keys::LETTER_N]) this->map.Update();

    this->event = SDL_Event{};

}

Editor::~Editor() noexcept {

    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();

}