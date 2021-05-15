#ifndef DEF_EDITOR_HPP
#define DEF_EDITOR_HPP

#include <SDL_render.h>
#include <SDL_events.h>
#include <unordered_map>
#include <vector>

#include "./GUI.hpp"
#include "./Map.hpp"

struct Commands final { // 574 bits, 71 octets

    std::unordered_map<SDL_Keycode, bool> keys;
    std::unordered_map<SDL_Keycode, bool> keys_once;
    std::unordered_map<std::uint8_t, bool> mouse;
    std::unordered_map<std::uint8_t, bool> mouse_once;

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

    Camera camera;
    std::vector<Theme> themes;
    Map<100, 100> map;

    SDL_Renderer* renderer;

    private:
    Commands commands;

    SDL_Event event;
    SDL_Window* window;

};

#endif //DEF_EDITOR_HPP