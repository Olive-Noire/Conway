#include "../Headers/Events.hpp"

void UpdateCommandsKeys(const SDL_Event &event, Commands &commands) noexcept {

    for (std::uint16_t i{0};i<240;i++) commands.keys_once[i] = false;

    switch (event.type) {

		case SDL_EventType::SDL_KEYDOWN:
        case SDL_EventType::SDL_KEYUP:

            switch(event.key.keysym.sym) {

                case SDL_KeyCode::SDLK_UNKNOWN: commands.keys[Keys::UNKOWN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_RETURN: commands.keys[Keys::RETURN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_ESCAPE: commands.keys[Keys::ESCAPE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_BACKSPACE: commands.keys[Keys::BACKSPACE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_TAB: commands.keys[Keys::TAB] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_SPACE: commands.keys[Keys::SPACE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_EXCLAIM: commands.keys[Keys::EXCLAIM] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_QUOTEDBL: commands.keys[Keys::QUOTEDBL] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_HASH: commands.keys[Keys::HASH] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_PERCENT: commands.keys[Keys::PERCENT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_DOLLAR: commands.keys[Keys::DOLLAR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AMPERSAND: commands.keys[Keys::AMPERSAND] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_QUOTE: commands.keys[Keys::QUOTE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_LEFTPAREN: commands.keys[Keys::LEFTPAREN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_RIGHTPAREN: commands.keys[Keys::RIGHTPAREN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_ASTERISK: commands.keys[Keys::ASTERISK] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_PLUS: commands.keys[Keys::PLUS] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_COMMA: commands.keys[Keys::COMMA] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_MINUS: commands.keys[Keys::MINUS] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_PERIOD: commands.keys[Keys::PERIOD] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_SLASH: commands.keys[Keys::SLASH] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_0: commands.keys[Keys::DIGIT_ZERO] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_1: commands.keys[Keys::DIGIT_ONE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_2: commands.keys[Keys::DIGIT_TWO] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_3: commands.keys[Keys::DIGIT_THREE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_4: commands.keys[Keys::DIGIT_FOUR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_5: commands.keys[Keys::DIGIT_FIVE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_6: commands.keys[Keys::DIGIT_SIX] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_7: commands.keys[Keys::DIGIT_SEVEN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_8: commands.keys[Keys::DIGIT_EIGHT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_9: commands.keys[Keys::DIGIT_NINE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_COLON: commands.keys[Keys::COLON] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_SEMICOLON: commands.keys[Keys::SEMICOLON] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_LESS: commands.keys[Keys::LESS] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_EQUALS: commands.keys[Keys::EQUALS] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_GREATER: commands.keys[Keys::GREATER] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_QUESTION: commands.keys[Keys::QUESTION] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AT: commands.keys[Keys::AT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_LEFTBRACKET: commands.keys[Keys::LEFTBRACKET] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_BACKSLASH: commands.keys[Keys::BACKSLASH] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_RIGHTBRACKET: commands.keys[Keys::RIGHTBRACKET] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_CARET: commands.keys[Keys::CARET] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_UNDERSCORE: commands.keys[Keys::UNDERSCORE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_BACKQUOTE: commands.keys[Keys::BACKQUOTE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_a: commands.keys[Keys::LETTER_A] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_b: commands.keys[Keys::LETTER_B] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_c: commands.keys[Keys::LETTER_C] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_d: commands.keys[Keys::LETTER_D] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_e: commands.keys[Keys::LETTER_E] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_f: commands.keys[Keys::LETTER_F] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_g: commands.keys[Keys::LETTER_G] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_h: commands.keys[Keys::LETTER_H] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_i: commands.keys[Keys::LETTER_I] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_j: commands.keys[Keys::LETTER_J] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_k: commands.keys[Keys::LETTER_K] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_l: commands.keys[Keys::LETTER_L] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_m: commands.keys[Keys::LETTER_M] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_n: commands.keys[Keys::LETTER_N] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_o: commands.keys[Keys::LETTER_O] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_p: commands.keys[Keys::LETTER_P] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_q: commands.keys[Keys::LETTER_Q] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_r: commands.keys[Keys::LETTER_R] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_s: commands.keys[Keys::LETTER_S] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_t: commands.keys[Keys::LETTER_T] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_u: commands.keys[Keys::LETTER_U] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_v: commands.keys[Keys::LETTER_V] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_w: commands.keys[Keys::LETTER_W] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_x: commands.keys[Keys::LETTER_X] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_y: commands.keys[Keys::LETTER_Y] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_z: commands.keys[Keys::LETTER_Z] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F1: commands.keys[Keys::F1] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F2: commands.keys[Keys::F2] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F3: commands.keys[Keys::F3] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F4: commands.keys[Keys::F4] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F5: commands.keys[Keys::F5] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F6: commands.keys[Keys::F6] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F7: commands.keys[Keys::F7] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F8: commands.keys[Keys::F8] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F9: commands.keys[Keys::F9] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F10: commands.keys[Keys::F10] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F11: commands.keys[Keys::F11] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F12: commands.keys[Keys::F12] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_PRINTSCREEN: commands.keys[Keys::PRINTSCREEN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_SCROLLLOCK: commands.keys[Keys::SCROLLLOCK] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_PAUSE: commands.keys[Keys::PAUSE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_INSERT: commands.keys[Keys::INSERT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_HOME: commands.keys[Keys::HOME] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_PAGEUP: commands.keys[Keys::PAGEUP] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_END: commands.keys[Keys::END] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_PAGEDOWN: commands.keys[Keys::PAGEDOWN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_RIGHT: commands.keys[Keys::ARROW_RIGHT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_LEFT: commands.keys[Keys::ARROW_LEFT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_DOWN: commands.keys[Keys::ARROW_DOWN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_UP: commands.keys[Keys::ARROW_UP] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_NUMLOCKCLEAR: commands.keys[Keys::NUMLOCKCLEAR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_DIVIDE: commands.keys[Keys::KP_DIVIDE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_MULTIPLY: commands.keys[Keys::KP_MULTIPLY] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_MINUS: commands.keys[Keys::KP_MINUS] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_PLUS: commands.keys[Keys::KP_PLUS] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_ENTER: commands.keys[Keys::KP_ENTER] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_1: commands.keys[Keys::KP_DIGIT_1] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_2: commands.keys[Keys::KP_DIGIT_2] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_3: commands.keys[Keys::KP_DIGIT_3] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_4: commands.keys[Keys::KP_DIGIT_4] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_5: commands.keys[Keys::KP_DIGIT_5] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_6: commands.keys[Keys::KP_DIGIT_6] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_7: commands.keys[Keys::KP_DIGIT_7] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_8: commands.keys[Keys::KP_DIGIT_8] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_9: commands.keys[Keys::KP_DIGIT_9] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_0: commands.keys[Keys::KP_DIGIT_0] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_PERIOD: commands.keys[Keys::KP_PERIOD] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_APPLICATION: commands.keys[Keys::APPLICATION] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_POWER: commands.keys[Keys::POWER] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_EQUALS: commands.keys[Keys::KP_EQUALS] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F13: commands.keys[Keys::F13] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F14: commands.keys[Keys::F14] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F15: commands.keys[Keys::F15] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F16: commands.keys[Keys::F16] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F17: commands.keys[Keys::F17] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F18: commands.keys[Keys::F18] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F19: commands.keys[Keys::F19] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F20: commands.keys[Keys::F20] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F21: commands.keys[Keys::F21] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F22: commands.keys[Keys::F22] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F23: commands.keys[Keys::F23] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_F24: commands.keys[Keys::F24] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_EXECUTE: commands.keys[Keys::EXECUTE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_HELP: commands.keys[Keys::HELP] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_MENU: commands.keys[Keys::MENU] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_SELECT: commands.keys[Keys::SELECT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_STOP: commands.keys[Keys::STOP] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AGAIN: commands.keys[Keys::AGAIN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_UNDO: commands.keys[Keys::UNDO] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_CUT: commands.keys[Keys::CUT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_COPY: commands.keys[Keys::COPY] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_PASTE: commands.keys[Keys::PASTE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_FIND: commands.keys[Keys::FIND] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_MUTE: commands.keys[Keys::MUTE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_VOLUMEUP: commands.keys[Keys::VOLUMEUP] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_VOLUMEDOWN: commands.keys[Keys::VOLUMEDOWN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_COMMA: commands.keys[Keys::KP_COMMA] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_EQUALSAS400: commands.keys[Keys::KP_EQUALSAS400] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_ALTERASE: commands.keys[Keys::ALTERASE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_SYSREQ: commands.keys[Keys::SYSREQ] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_CANCEL: commands.keys[Keys::CANCEL] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_CLEAR: commands.keys[Keys::CLEAR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_PRIOR: commands.keys[Keys::PRIOR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_RETURN2: commands.keys[Keys::RETURN2] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_SEPARATOR: commands.keys[Keys::SEPARATOR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_OUT: commands.keys[Keys::OUT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_OPER: commands.keys[Keys::OPER] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_CLEARAGAIN: commands.keys[Keys::CLEARAGAIN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_CRSEL: commands.keys[Keys::CRSEL] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_EXSEL: commands.keys[Keys::EXSEL] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_00: commands.keys[Keys::KP_00] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_000: commands.keys[Keys::KP_000] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_THOUSANDSSEPARATOR: commands.keys[Keys::THOUSANDSSEPARATOR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_DECIMALSEPARATOR: commands.keys[Keys::DECIMALSEPARATOR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_CURRENCYUNIT: commands.keys[Keys::CURRENCYUNIT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_CURRENCYSUBUNIT: commands.keys[Keys::CURRENCYSUBUNIT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_LEFTPAREN: commands.keys[Keys::KP_LEFTPAREN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_RIGHTPAREN: commands.keys[Keys::KP_RIGHTPAREN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_LEFTBRACE: commands.keys[Keys::KP_RIGHTBRACE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_TAB: commands.keys[Keys::KP_TAB] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_BACKSPACE: commands.keys[Keys::KP_BACKSPACE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_A: commands.keys[Keys::KP_LETTER_A] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_B: commands.keys[Keys::KP_LETTER_B] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_C: commands.keys[Keys::KP_LETTER_C] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_D: commands.keys[Keys::KP_LETTER_D] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_E: commands.keys[Keys::KP_LETTER_E] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_F: commands.keys[Keys::KP_LETTER_F] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_XOR: commands.keys[Keys::KP_XOR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_POWER: commands.keys[Keys::KP_POWER] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_LESS: commands.keys[Keys::KP_LESS] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_GREATER: commands.keys[Keys::KP_GREATER] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_AMPERSAND: commands.keys[Keys::KP_AMPERSAND] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_DBLAMPERSAND: commands.keys[Keys::KP_DBLAMPERSAND] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_VERTICALBAR: commands.keys[Keys::KP_VERTICALBAR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_DBLVERTICALBAR: commands.keys[Keys::KP_DBLVERTICALBAR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_COLON: commands.keys[Keys::KP_COLON] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_HASH: commands.keys[Keys::KP_HASH] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_SPACE: commands.keys[Keys::KP_SPACE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_AT: commands.keys[Keys::KP_AT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_EXCLAM: commands.keys[Keys::KP_EXCLAM] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_MEMSTORE: commands.keys[Keys::KP_MEMSTORE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_MEMRECALL: commands.keys[Keys::KP_MEMRECALL] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_MEMCLEAR: commands.keys[Keys::KP_MEMCLEAR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_MEMADD: commands.keys[Keys::KP_MEMADD] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_MEMSUBTRACT: commands.keys[Keys::KP_MEMSUBTRACT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_MEMMULTIPLY: commands.keys[Keys::KP_MEMMULTIPLY] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_MEMDIVIDE: commands.keys[Keys::KP_MEMDIVIDE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_PLUSMINUS: commands.keys[Keys::KP_PLUSMINUS] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_CLEAR: commands.keys[Keys::KP_CLEAR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_CLEARENTRY: commands.keys[Keys::KP_CLEARENTRY] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_BINARY: commands.keys[Keys::KP_BINARY] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_OCTAL: commands.keys[Keys::KP_OCTAL] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_DECIMAL: commands.keys[Keys::KP_DECIMAL] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_KP_HEXADECIMAL: commands.keys[Keys::KP_HEXADECIMAL] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_LCTRL: commands.keys[Keys::LCTRL] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_LSHIFT: commands.keys[Keys::LSHIFT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_LALT: commands.keys[Keys::LALT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_LGUI: commands.keys[Keys::LGUI] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_RCTRL: commands.keys[Keys::F1] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_RSHIFT: commands.keys[Keys::RSHIFT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_RALT: commands.keys[Keys::RALT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_RGUI: commands.keys[Keys::RGUI] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_MODE: commands.keys[Keys::MODE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AUDIONEXT: commands.keys[Keys::AUDIONEXT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AUDIOPREV: commands.keys[Keys::AUDIOPREV] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AUDIOSTOP: commands.keys[Keys::AUDIOSTOP] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AUDIOPLAY: commands.keys[Keys::AUDIOPLAY] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AUDIOMUTE: commands.keys[Keys::AUDIOMUTE] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_MEDIASELECT: commands.keys[Keys::MEDIASELECT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_WWW: commands.keys[Keys::WWW] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_MAIL: commands.keys[Keys::MAIL] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_CALCULATOR: commands.keys[Keys::CALCULATOR] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_COMPUTER: commands.keys[Keys::COMPUTER] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AC_SEARCH: commands.keys[Keys::AC_SEARCH] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AC_HOME: commands.keys[Keys::AC_HOME] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AC_BACK: commands.keys[Keys::AC_BACK] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AC_FORWARD: commands.keys[Keys::AC_FORWARD] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AC_STOP: commands.keys[Keys::AC_STOP] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AC_REFRESH: commands.keys[Keys::AC_REFRESH] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AC_BOOKMARKS: commands.keys[Keys::AC_BOOKMARKS] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_BRIGHTNESSDOWN: commands.keys[Keys::BRIGHTNESSDOWN] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_BRIGHTNESSUP: commands.keys[Keys::BRIGHTNESSUP] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_EJECT: commands.keys[Keys::EJECT] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_SLEEP: commands.keys[Keys::SLEEP] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_APP1: commands.keys[Keys::APP1] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_APP2: commands.keys[Keys::APP2] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AUDIOREWIND: commands.keys[Keys::AUDIOREWIND] = (event.type == SDL_EventType::SDL_KEYDOWN); break;
                case SDL_KeyCode::SDLK_AUDIOFASTFORWARD: commands.keys[Keys::AUDIOFASTFORWARD] = (event.type == SDL_EventType::SDL_KEYDOWN); break;

            }

		break;

		default:
		break;

	}

    for (std::uint16_t i{0};i<240;i++) if (commands.keys[i] && event.type == SDL_EventType::SDL_KEYDOWN && !commands.keys_once[i]) commands.keys_once[i] = true; // Pas tout à fait au point...

}

void UpdateCommandsMouse(const SDL_Event &event, Commands &commands) noexcept {

    for (bool &b : commands.mouse_once) b = false;

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