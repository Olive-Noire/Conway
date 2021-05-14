#ifndef DEF_MAP_HPP
#define DEF_MAP_HPP

#include <array>

struct Rules final { // 16 bits, 2 octets

    bool birth[8]{false, false, false, true, false, false, false, false};
    bool survive[8]{false, false, true, true, false, false, false, false};

};

template<std::size_t w, std::size_t h>
class Map final { // 145 bits, 18 octets + w*h bits

    public:
    constexpr Map() noexcept { Clear(); }

    constexpr void Clear() noexcept {

        for (std::uint8_t x{0};x<w;x++) for (std::uint8_t y{0};y<h;y++) this->surface[x][y] = false;

    }

    constexpr void Update() noexcept {

        bool next[w][h];

        for (std::size_t x{0};x<w;x++) for (std::size_t y{0};y<h;y++) {

            std::uint8_t adjacents{0};

            if (x < w && this->surface[x+1][y]) adjacents++;
            if (x > 0 && this->surface[x-1][y]) adjacents++;
            if (y < h && this->surface[x][y+1]) adjacents++;
            if (y > 0 && this->surface[x][y-1]) adjacents++;

            if (x < w && y < h && this->surface[x+1][y+1]) adjacents++;
            if (x > 0 && y < h-1 && this->surface[x-1][y+1]) adjacents++;
            if (x < w-1 && y > 0 && this->surface[x+1][y-1]) adjacents++;
            if (x > 0 && y > 0 && this->surface[x-1][y-1]) adjacents++;

            // Regles
            next[x][y] = false;
            if (!this->surface[x][y] && rules.birth[adjacents]) next[x][y] = true;
            if (this->surface[x][y] && rules.survive[adjacents]) next[x][y] = true;

        }

        for (std::size_t x{0};x<w;x++) for (std::size_t y{0};y<h;y++) this->surface[x][y] = next[x][y];

    }

    bool surface[w][h];

    const std::size_t width{w};
    const std::size_t height{h};

    constexpr const Rules& GetRules() const { return rules; }
    constexpr void SetRules(const Rules &r) { rules = r; }

    private:
    Rules rules;

};

#endif //DEF_MAP_HPP