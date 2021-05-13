#ifndef DEF_GUI_HPP
#define DEF_GUI_HPP

// Pour l'instant rien d'important n'est implémenté ici

#include <SDL_pixels.h>
#include <SDL_rect.h>

// En attendant les thèmes de couleurs...
#define CELL_COLOR SDL_Color{255, 255, 255, 255}
#define GRID_COLOR SDL_Color{255, 255, 0, 255} // And borders
#define PAUSE_COLOR SDL_Color{255, 0, 0, 255}
#define CURSOR_COLOR SDL_Color{0, 255, 0, 255}
#define BACKGROUND_COLOR SDL_Color{0, 0, 0, 0}
#define RENDER_GRID false

constexpr bool AABB(const SDL_Rect &a,const SDL_Rect &b) { return a.x+a.w>=b.x&&a.x<=b.x+b.w&&a.y+a.h>=b.y&&a.y<=b.y+b.h; }

#endif //DEF_GUI_HPP