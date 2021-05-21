#ifndef DEF_EVENTS_HPP
#define DEF_EVENTS_HPP

#include "./Editor.hpp"

void UpdateCommandsKeys(const SDL_Event &event, Commands &commands) noexcept;
void UpdateCommandsMouse(const SDL_Event &event, Commands &commands) noexcept;
void UpdateWindow(const SDL_Event &event) noexcept;

#endif //DEF_EVENTS_HPP