#include "../Headers/Events.hpp"

void UpdateCommandsKeys(const SDL_Event &event, Commands &commands) noexcept {

    for (std::pair<const SDL_Keycode, bool> &k : commands.keys_once) { k.second = false; }

    switch (event.type) {

		case SDL_EventType::SDL_KEYDOWN:
        case SDL_EventType::SDL_KEYUP:

            commands.keys[event.key.keysym.sym] = commands.keys_once[event.key.keysym.sym] = (event.type == SDL_KEYDOWN);

		break;

		default:
		break;

	}

}

void UpdateCommandsMouse(const SDL_Event &event, Commands &commands) noexcept {

    for (std::pair<const std::uint8_t, bool> &m : commands.mouse_once) { m.second = false; }

    switch(event.type) {

        case SDL_EventType::SDL_MOUSEBUTTONDOWN:
        commands.mouse[event.button.button] = commands.mouse_once[event.button.button] = true;
        break;

        case SDL_EventType::SDL_MOUSEBUTTONUP:
        commands.mouse[event.button.button] = false;
        break;

        case SDL_EventType::SDL_MOUSEMOTION:
        commands.mouse_pos[0] = event.motion.x;
        commands.mouse_pos[1] = event.motion.y;
        commands.mouse_pos[2] = event.motion.xrel;
        commands.mouse_pos[3] = event.motion.yrel;
        break;

        case SDL_EventType::SDL_MOUSEWHEEL:
        commands.wheel = event.wheel.y;
        break;

        default:
        break;

    }

    if (event.type != SDL_EventType::SDL_MOUSEMOTION) {

        commands.mouse_pos[2] = 0;
        commands.mouse_pos[3] = 0;

    }

    if (event.type != SDL_EventType::SDL_MOUSEWHEEL) commands.wheel = 0;

}

void UpdateWindow(const SDL_Event &event) noexcept {

    switch (event.type) {

        case SDL_WindowEventID::SDL_WINDOWEVENT_RESIZED:
        break;
    
        default:
        break;
        
    }

}