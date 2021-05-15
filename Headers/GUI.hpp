#ifndef DEF_GUI_HPP
#define DEF_GUI_HPP

// Pour l'instant rien d'important n'est implémenté ici

#include <SDL_pixels.h>
#include <SDL_rect.h>

#define ZOOM_VIEW_GRID 0
#define RENDER_GRID true

// Cell, Grid, Pause, Cursor, Background
struct Theme final {

    SDL_Color cell;
    SDL_Color grid;
    SDL_Color pause;
    SDL_Color cursor;
    SDL_Color background;

};

constexpr bool AABB(const SDL_Rect &a,const SDL_Rect &b) noexcept { return a.x+a.w>=b.x&&a.x<=b.x+b.w&&a.y+a.h>=b.y&&a.y<=b.y+b.h; }

#endif //DEF_GUI_HPP