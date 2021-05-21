#include "../Headers/Editor.hpp"

#include <SDL.h>

#include "../Headers/Events.hpp"

Editor::Editor() {

    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTS | SDL_INIT_VIDEO) != 0) return;

    this->window = SDL_CreateWindow("Conway",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Screen::width,Screen::height,SDL_WindowFlags::SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(this->window,0,SDL_RendererFlags::SDL_RENDERER_ACCELERATED);

    this->pause = true;
    this->camera.zoom = Screen::height/this->map.height;

    // Basic
    this->themes.push_back(Theme{SDL_Color{255, 255, 255, 255},SDL_Color{255, 255, 255, 255},SDL_Color{255, 0, 0, 255},SDL_Color{0, 255, 0, 255},SDL_Color{0, 0, 0, 0}});

    // Dark
    this->themes.push_back(Theme{SDL_Color{65, 108, 119, 255},SDL_Color{0, 0, 0, 0},SDL_Color{255, 0, 0, 255},SDL_Color{255, 0, 0, 255},SDL_Color{35, 39, 42, 255}});

    // Light
    this->themes.push_back(Theme{SDL_Color{0, 0, 0, 255},SDL_Color{200, 200, 200, 255},SDL_Color{255, 0, 0, 255},SDL_Color{0, 255, 0, 255},SDL_Color{255, 255, 255, 255}});

    // Matrix
    this->themes.push_back(Theme{SDL_Color{0, 255, 0, 255},SDL_Color{0, 255, 0, 255},SDL_Color{255, 0, 0, 255},SDL_Color{0, 255, 0, 255},SDL_Color{0, 0, 0, 0}});

    // Game Of life
    this->themes.push_back(Theme{SDL_Color{255, 255, 0, 255},SDL_Color{153, 153, 153, 255}, SDL_Color{255, 0, 0, 255}, SDL_Color{153, 153, 153, 255}, SDL_Color{126, 126, 126, 255}});

    this->run = true;
 
}

void Editor::Render() const noexcept {

    SDL_RenderClear(this->renderer);
    constexpr std::size_t current_theme{1};

    for (std::size_t x{0};x<this->map.width;x++) for (std::size_t y{0};y<this->map.height;y++) {

        const SDL_Rect cell{(signed int)x*this->camera.zoom-this->camera.x,(signed int)y*this->camera.zoom-this->camera.y,(signed int)this->camera.zoom,(signed int)this->camera.zoom};

        if (this->map.surface[x][y]) {
            
            SDL_SetRenderDrawColor(this->renderer, this->themes[current_theme].cell.r, this->themes[current_theme].cell.g, this->themes[current_theme].cell.b, this->themes[current_theme].cell.a);
            SDL_RenderFillRect(this->renderer, &cell);

        }

    }

    {

        const SDL_Rect border{-this->camera.x-1,-this->camera.y-1,(signed int)this->map.width*this->camera.zoom+2,(signed int)this->map.height*this->camera.zoom+2};
        SDL_SetRenderDrawColor(this->renderer, this->themes[current_theme].grid.r, this->themes[current_theme].grid.g, this->themes[current_theme].grid.b, this->themes[current_theme].grid.a);
        SDL_RenderDrawRect(this->renderer, &border);

        if (RENDER_GRID && this->camera.zoom>ZOOM_VIEW_GRID && this->camera.zoom>1) {
        
            for (std::size_t i{0};i<this->map.width+1;i++) SDL_RenderDrawLine(this->renderer, -this->camera.x, -this->camera.y+i*this->camera.zoom+(i == this->map.width), -this->camera.x+this->map.width*this->camera.zoom, -this->camera.y+i*this->camera.zoom+(i == this->map.width));
            for (std::size_t i{0};i<this->map.height+1;i++) SDL_RenderDrawLine(this->renderer, -this->camera.x+i*this->camera.zoom+(i == this->map.height), -this->camera.y, -this->camera.x+i*this->camera.zoom+(i == this->map.height), -this->camera.y+this->map.height*this->camera.zoom);

        }

    }

    if (AABB(SDL_Rect{this->commands.mouse_pos[0],this->commands.mouse_pos[1],1,1},SDL_Rect{-this->camera.x-1,-this->camera.y-1,(signed int)this->map.width*this->camera.zoom,(signed int)this->map.height*this->camera.zoom})) {

        const SDL_Rect cursor{(this->commands.mouse_pos[0]+this->camera.x)/this->camera.zoom*this->camera.zoom-this->camera.x,(this->commands.mouse_pos[1]+this->camera.y)/this->camera.zoom*this->camera.zoom-this->camera.y,(signed int)this->camera.zoom+1,(signed int)this->camera.zoom+1};
        SDL_SetRenderDrawColor(this->renderer, this->themes[current_theme].cursor.r, this->themes[current_theme].cursor.g, this->themes[current_theme].cursor.b, this->themes[current_theme].cursor.a);
        SDL_RenderDrawRect(this->renderer, &cursor);

    }

    {

        unsigned int size{0};
        if (Screen::width>Screen::height) size = Screen::height/40; else size = Screen::width/40;

        if (pause) {


            const SDL_Rect bar1{Screen::width-(int)size*3,Screen::height-int(size*2+size/2),(int)size,(int)size*2};
            const SDL_Rect bar2{bar1.x+bar1.w+bar1.w/2,bar1.y,bar1.w,bar1.h};

            SDL_SetRenderDrawColor(this->renderer, this->themes[current_theme].pause.r, this->themes[current_theme].pause.g, this->themes[current_theme].pause.b, this->themes[current_theme].pause.a);
            SDL_RenderFillRect(this->renderer, &bar1);
            SDL_RenderFillRect(this->renderer, &bar2);

        }/* else {

            SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 255);
            for (std::uint8_t i{0};i<size*2;i++) {

                SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 255);
                SDL_RenderDrawLine(this->renderer, Screen::width-(Screen::width/20+size/2)+i, Screen::height-size/2-size*2+i/2, Screen::width-(Screen::width/10+size/2)+i, Screen::height-(Screen::height/80+i));
                SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
                SDL_RenderDrawPoint(this->renderer, Screen::width-(Screen::width/10+size/2)+i, Screen::height-(Screen::height/80+i));

            }

        }*/

    }

    SDL_SetRenderDrawColor(this->renderer, this->themes[current_theme].background.r, this->themes[current_theme].background.g, this->themes[current_theme].background.b, this->themes[current_theme].background.a);
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
    if (this->commands.keys_once[SDL_KeyCode::SDLK_SPACE]) this->pause=!this->pause;

    // Déplace la caméra à l'aide des flèches
    if (!this->commands.keys[SDL_KeyCode::SDLK_RIGHT]) this->camera.x-=5;
    if (!this->commands.keys[SDL_KeyCode::SDLK_LEFT]) this->camera.x+=5;
    if (!this->commands.keys[SDL_KeyCode::SDLK_UP]) this->camera.y+=5;
    if (!this->commands.keys[SDL_KeyCode::SDLK_DOWN]) this->camera.y-=5;

    // Clear la Map
    if (this->commands.keys_once[SDL_KeyCode::SDLK_c]) this->map.Clear();

    // CTRL + Keys
    if (this->commands.keys[SDL_KeyCode::SDLK_LCTRL] || this->commands.keys[SDL_KeyCode::SDLK_RCTRL]) {

        // Zoom CTRL + PLUS
        if (this->commands.keys_once[SDL_KeyCode::SDLK_PLUS] || this->commands.keys_once[SDL_KeyCode::SDLK_KP_PLUS]) {
            
            this->camera.zoom++;
            this->camera.x-=(Screen::width/2-this->commands.mouse_pos[0])/this->camera.zoom;
            this->camera.y-=(Screen::height/2-this->commands.mouse_pos[1])/this->camera.zoom;

        }

        // Dezoom CTRL + MINUS
        if ((this->commands.keys_once[SDL_KeyCode::SDLK_MINUS] || this->commands.keys_once[SDL_KeyCode::SDLK_KP_MINUS]) && this->camera.zoom>1) {
            
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
    if (!this->pause || this->commands.keys_once[SDL_KeyCode::SDLK_n]) this->map.Update();

    this->event = SDL_Event{};

}

Editor::~Editor() noexcept {

    if (this->renderer != nullptr) SDL_DestroyRenderer(this->renderer);
    if (this->window != nullptr) SDL_DestroyWindow(this->window);
    SDL_Quit();

}