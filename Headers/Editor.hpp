#ifndef DEF_EDITOR_HPP
#define DEF_EDITOR_HPP

#include <SDL_render.h>
#include <SDL_events.h>
#include "./Map.hpp"

struct Commands final { // 574 bits, 71 octets

    bool keys[240];
    bool keys_once[240];
    bool mouse[7];
    bool mouse_once[7];

    std::uint16_t sensibility{1};
    std::uint16_t mouse_pos[4];

    std::int8_t wheel;

};

struct Camera final { // 48 bits, 6 octets

    std::int16_t x{0};
    std::int16_t y{0};

    std::uint16_t zoom{1};

};

namespace Screen {
  constexpr std::uint16_t width{700};
  constexpr std::uint16_t height{700};
}

// !! Nécessite qu'une seule instance !! Encadre la SDL + stocke les trucs importants + Gestion de la main loop
class Editor final { // 84864 bits, 10608 octets, 10 Ko (SDL qui prend énormément)

    public:
    Editor();
    void Render() const noexcept;
    void Update() noexcept;
    ~Editor() noexcept;

    bool run;
    bool pause;

    Map<100, 100> map;
    Camera camera;

    SDL_Renderer* renderer;

    private:
    Commands commands;

    SDL_Window* window;
    SDL_Event event;

};

#endif //DEF_EDITOR_HPP