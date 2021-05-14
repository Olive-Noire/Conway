#ifndef DEF_EDITOR_HPP
#define DEF_EDITOR_HPP

#include <SDL_render.h>
#include <SDL_events.h>
#include <array>

struct Commands final {

    bool keys[240],keys_once[240],mouse[7];
    std::uint16_t sensibility{1},mouse_pos[4];
    std::int8_t wheel;

};

struct Camera final {

    std::int16_t x{0},y{0};
    std::uint16_t zoom{1};

};

class Editor final {

    public:
    static void Init(void);
    static void Render(void) noexcept;
    static void Update(void) noexcept;
    static void Quit(void) noexcept;

    static bool run,pause;
    static std::array<std::array<bool, 100>, 100> map;
    static constexpr std::uint16_t width{700},height{700};

    static Camera camera;
    static Commands commands;

    static SDL_Renderer* renderer;
    static SDL_Window* window;

    private:
    static SDL_Event event;

};

#endif //DEF_EDITOR_HPP
