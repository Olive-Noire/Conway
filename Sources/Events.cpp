#include "../Headers/Events.hpp"

#include "../Headers/Editor.hpp"

void UpdateKeys(const SDL_Event &event) noexcept {

    for (std::uint16_t i{0};i<240;i++) Editor::commands.keys_once[Keys(i)] = false;

    switch (event.type) {

	case SDL_KEYDOWN:
        case SDL_KEYUP:

            switch(event.key.keysym.sym) {

                case SDLK_UNKNOWN: Editor::commands.keys[Keys::UNKOWN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_RETURN: Editor::commands.keys[Keys::RETURN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_ESCAPE: Editor::commands.keys[Keys::ESCAPE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_BACKSPACE: Editor::commands.keys[Keys::BACKSPACE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_TAB: Editor::commands.keys[Keys::TAB] = (event.type == SDL_KEYDOWN); break;
                case SDLK_SPACE: Editor::commands.keys[Keys::SPACE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_EXCLAIM: Editor::commands.keys[Keys::EXCLAIM] = (event.type == SDL_KEYDOWN); break;
                case SDLK_QUOTEDBL: Editor::commands.keys[Keys::QUOTEDBL] = (event.type == SDL_KEYDOWN); break;
                case SDLK_HASH: Editor::commands.keys[Keys::HASH] = (event.type == SDL_KEYDOWN); break;
                case SDLK_PERCENT: Editor::commands.keys[Keys::PERCENT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_DOLLAR: Editor::commands.keys[Keys::DOLLAR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AMPERSAND: Editor::commands.keys[Keys::AMPERSAND] = (event.type == SDL_KEYDOWN); break;
                case SDLK_QUOTE: Editor::commands.keys[Keys::QUOTE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_LEFTPAREN: Editor::commands.keys[Keys::LEFTPAREN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_RIGHTPAREN: Editor::commands.keys[Keys::RIGHTPAREN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_ASTERISK: Editor::commands.keys[Keys::ASTERISK] = (event.type == SDL_KEYDOWN); break;
                case SDLK_PLUS: Editor::commands.keys[Keys::PLUS] = (event.type == SDL_KEYDOWN); break;
                case SDLK_COMMA: Editor::commands.keys[Keys::COMMA] = (event.type == SDL_KEYDOWN); break;
                case SDLK_MINUS: Editor::commands.keys[Keys::MINUS] = (event.type == SDL_KEYDOWN); break;
                case SDLK_PERIOD: Editor::commands.keys[Keys::PERIOD] = (event.type == SDL_KEYDOWN); break;
                case SDLK_SLASH: Editor::commands.keys[Keys::SLASH] = (event.type == SDL_KEYDOWN); break;
                case SDLK_0: Editor::commands.keys[Keys::DIGIT_ZERO] = (event.type == SDL_KEYDOWN); break;
                case SDLK_1: Editor::commands.keys[Keys::DIGIT_ONE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_2: Editor::commands.keys[Keys::DIGIT_TWO] = (event.type == SDL_KEYDOWN); break;
                case SDLK_3: Editor::commands.keys[Keys::DIGIT_THREE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_4: Editor::commands.keys[Keys::DIGIT_FOUR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_5: Editor::commands.keys[Keys::DIGIT_FIVE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_6: Editor::commands.keys[Keys::DIGIT_SIX] = (event.type == SDL_KEYDOWN); break;
                case SDLK_7: Editor::commands.keys[Keys::DIGIT_SEVEN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_8: Editor::commands.keys[Keys::DIGIT_EIGHT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_9: Editor::commands.keys[Keys::DIGIT_NINE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_COLON: Editor::commands.keys[Keys::COLON] = (event.type == SDL_KEYDOWN); break;
                case SDLK_SEMICOLON: Editor::commands.keys[Keys::SEMICOLON] = (event.type == SDL_KEYDOWN); break;
                case SDLK_LESS: Editor::commands.keys[Keys::LESS] = (event.type == SDL_KEYDOWN); break;
                case SDLK_EQUALS: Editor::commands.keys[Keys::EQUALS] = (event.type == SDL_KEYDOWN); break;
                case SDLK_GREATER: Editor::commands.keys[Keys::GREATER] = (event.type == SDL_KEYDOWN); break;
                case SDLK_QUESTION: Editor::commands.keys[Keys::QUESTION] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AT: Editor::commands.keys[Keys::AT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_LEFTBRACKET: Editor::commands.keys[Keys::LEFTBRACKET] = (event.type == SDL_KEYDOWN); break;
                case SDLK_BACKSLASH: Editor::commands.keys[Keys::BACKSLASH] = (event.type == SDL_KEYDOWN); break;
                case SDLK_RIGHTBRACKET: Editor::commands.keys[Keys::RIGHTBRACKET] = (event.type == SDL_KEYDOWN); break;
                case SDLK_CARET: Editor::commands.keys[Keys::CARET] = (event.type == SDL_KEYDOWN); break;
                case SDLK_UNDERSCORE: Editor::commands.keys[Keys::UNDERSCORE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_BACKQUOTE: Editor::commands.keys[Keys::BACKQUOTE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_a: Editor::commands.keys[Keys::LETTER_A] = (event.type == SDL_KEYDOWN); break;
                case SDLK_b: Editor::commands.keys[Keys::LETTER_B] = (event.type == SDL_KEYDOWN); break;
                case SDLK_c: Editor::commands.keys[Keys::LETTER_C] = (event.type == SDL_KEYDOWN); break;
                case SDLK_d: Editor::commands.keys[Keys::LETTER_D] = (event.type == SDL_KEYDOWN); break;
                case SDLK_e: Editor::commands.keys[Keys::LETTER_E] = (event.type == SDL_KEYDOWN); break;
                case SDLK_f: Editor::commands.keys[Keys::LETTER_F] = (event.type == SDL_KEYDOWN); break;
                case SDLK_g: Editor::commands.keys[Keys::LETTER_G] = (event.type == SDL_KEYDOWN); break;
                case SDLK_h: Editor::commands.keys[Keys::LETTER_H] = (event.type == SDL_KEYDOWN); break;
                case SDLK_i: Editor::commands.keys[Keys::LETTER_I] = (event.type == SDL_KEYDOWN); break;
                case SDLK_j: Editor::commands.keys[Keys::LETTER_J] = (event.type == SDL_KEYDOWN); break;
                case SDLK_k: Editor::commands.keys[Keys::LETTER_K] = (event.type == SDL_KEYDOWN); break;
                case SDLK_l: Editor::commands.keys[Keys::LETTER_L] = (event.type == SDL_KEYDOWN); break;
                case SDLK_m: Editor::commands.keys[Keys::LETTER_M] = (event.type == SDL_KEYDOWN); break;
                case SDLK_n: Editor::commands.keys[Keys::LETTER_N] = (event.type == SDL_KEYDOWN); break;
                case SDLK_o: Editor::commands.keys[Keys::LETTER_O] = (event.type == SDL_KEYDOWN); break;
                case SDLK_p: Editor::commands.keys[Keys::LETTER_P] = (event.type == SDL_KEYDOWN); break;
                case SDLK_q: Editor::commands.keys[Keys::LETTER_Q] = (event.type == SDL_KEYDOWN); break;
                case SDLK_r: Editor::commands.keys[Keys::LETTER_R] = (event.type == SDL_KEYDOWN); break;
                case SDLK_s: Editor::commands.keys[Keys::LETTER_S] = (event.type == SDL_KEYDOWN); break;
                case SDLK_t: Editor::commands.keys[Keys::LETTER_T] = (event.type == SDL_KEYDOWN); break;
                case SDLK_u: Editor::commands.keys[Keys::LETTER_U] = (event.type == SDL_KEYDOWN); break;
                case SDLK_v: Editor::commands.keys[Keys::LETTER_V] = (event.type == SDL_KEYDOWN); break;
                case SDLK_w: Editor::commands.keys[Keys::LETTER_W] = (event.type == SDL_KEYDOWN); break;
                case SDLK_x: Editor::commands.keys[Keys::LETTER_X] = (event.type == SDL_KEYDOWN); break;
                case SDLK_y: Editor::commands.keys[Keys::LETTER_Y] = (event.type == SDL_KEYDOWN); break;
                case SDLK_z: Editor::commands.keys[Keys::LETTER_Z] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F1: Editor::commands.keys[Keys::F1] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F2: Editor::commands.keys[Keys::F2] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F3: Editor::commands.keys[Keys::F3] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F4: Editor::commands.keys[Keys::F4] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F5: Editor::commands.keys[Keys::F5] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F6: Editor::commands.keys[Keys::F6] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F7: Editor::commands.keys[Keys::F7] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F8: Editor::commands.keys[Keys::F8] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F9: Editor::commands.keys[Keys::F9] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F10: Editor::commands.keys[Keys::F10] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F11: Editor::commands.keys[Keys::F11] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F12: Editor::commands.keys[Keys::F12] = (event.type == SDL_KEYDOWN); break;
                case SDLK_PRINTSCREEN: Editor::commands.keys[Keys::PRINTSCREEN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_SCROLLLOCK: Editor::commands.keys[Keys::SCROLLLOCK] = (event.type == SDL_KEYDOWN); break;
                case SDLK_PAUSE: Editor::commands.keys[Keys::PAUSE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_INSERT: Editor::commands.keys[Keys::INSERT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_HOME: Editor::commands.keys[Keys::HOME] = (event.type == SDL_KEYDOWN); break;
                case SDLK_PAGEUP: Editor::commands.keys[Keys::PAGEUP] = (event.type == SDL_KEYDOWN); break;
                case SDLK_END: Editor::commands.keys[Keys::END] = (event.type == SDL_KEYDOWN); break;
                case SDLK_PAGEDOWN: Editor::commands.keys[Keys::PAGEDOWN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_RIGHT: Editor::commands.keys[Keys::ARROW_RIGHT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_LEFT: Editor::commands.keys[Keys::ARROW_LEFT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_DOWN: Editor::commands.keys[Keys::ARROW_DOWN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_UP: Editor::commands.keys[Keys::ARROW_UP] = (event.type == SDL_KEYDOWN); break;
                case SDLK_NUMLOCKCLEAR: Editor::commands.keys[Keys::NUMLOCKCLEAR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_DIVIDE: Editor::commands.keys[Keys::KP_DIVIDE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_MULTIPLY: Editor::commands.keys[Keys::KP_MULTIPLY] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_MINUS: Editor::commands.keys[Keys::KP_MINUS] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_PLUS: Editor::commands.keys[Keys::KP_PLUS] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_ENTER: Editor::commands.keys[Keys::KP_ENTER] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_1: Editor::commands.keys[Keys::KP_DIGIT_1] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_2: Editor::commands.keys[Keys::KP_DIGIT_2] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_3: Editor::commands.keys[Keys::KP_DIGIT_3] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_4: Editor::commands.keys[Keys::KP_DIGIT_4] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_5: Editor::commands.keys[Keys::KP_DIGIT_5] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_6: Editor::commands.keys[Keys::KP_DIGIT_6] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_7: Editor::commands.keys[Keys::KP_DIGIT_7] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_8: Editor::commands.keys[Keys::KP_DIGIT_8] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_9: Editor::commands.keys[Keys::KP_DIGIT_9] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_0: Editor::commands.keys[Keys::KP_DIGIT_0] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_PERIOD: Editor::commands.keys[Keys::KP_PERIOD] = (event.type == SDL_KEYDOWN); break;
                case SDLK_APPLICATION: Editor::commands.keys[Keys::APPLICATION] = (event.type == SDL_KEYDOWN); break;
                case SDLK_POWER: Editor::commands.keys[Keys::POWER] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_EQUALS: Editor::commands.keys[Keys::KP_EQUALS] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F13: Editor::commands.keys[Keys::F13] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F14: Editor::commands.keys[Keys::F14] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F15: Editor::commands.keys[Keys::F15] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F16: Editor::commands.keys[Keys::F16] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F17: Editor::commands.keys[Keys::F17] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F18: Editor::commands.keys[Keys::F18] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F19: Editor::commands.keys[Keys::F19] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F20: Editor::commands.keys[Keys::F20] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F21: Editor::commands.keys[Keys::F21] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F22: Editor::commands.keys[Keys::F22] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F23: Editor::commands.keys[Keys::F23] = (event.type == SDL_KEYDOWN); break;
                case SDLK_F24: Editor::commands.keys[Keys::F24] = (event.type == SDL_KEYDOWN); break;
                case SDLK_EXECUTE: Editor::commands.keys[Keys::EXECUTE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_HELP: Editor::commands.keys[Keys::HELP] = (event.type == SDL_KEYDOWN); break;
                case SDLK_MENU: Editor::commands.keys[Keys::MENU] = (event.type == SDL_KEYDOWN); break;
                case SDLK_SELECT: Editor::commands.keys[Keys::SELECT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_STOP: Editor::commands.keys[Keys::STOP] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AGAIN: Editor::commands.keys[Keys::AGAIN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_UNDO: Editor::commands.keys[Keys::UNDO] = (event.type == SDL_KEYDOWN); break;
                case SDLK_CUT: Editor::commands.keys[Keys::CUT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_COPY: Editor::commands.keys[Keys::COPY] = (event.type == SDL_KEYDOWN); break;
                case SDLK_PASTE: Editor::commands.keys[Keys::PASTE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_FIND: Editor::commands.keys[Keys::FIND] = (event.type == SDL_KEYDOWN); break;
                case SDLK_MUTE: Editor::commands.keys[Keys::MUTE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_VOLUMEUP: Editor::commands.keys[Keys::VOLUMEUP] = (event.type == SDL_KEYDOWN); break;
                case SDLK_VOLUMEDOWN: Editor::commands.keys[Keys::VOLUMEDOWN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_COMMA: Editor::commands.keys[Keys::KP_COMMA] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_EQUALSAS400: Editor::commands.keys[Keys::KP_EQUALSAS400] = (event.type == SDL_KEYDOWN); break;
                case SDLK_ALTERASE: Editor::commands.keys[Keys::ALTERASE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_SYSREQ: Editor::commands.keys[Keys::SYSREQ] = (event.type == SDL_KEYDOWN); break;
                case SDLK_CANCEL: Editor::commands.keys[Keys::CANCEL] = (event.type == SDL_KEYDOWN); break;
                case SDLK_CLEAR: Editor::commands.keys[Keys::CLEAR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_PRIOR: Editor::commands.keys[Keys::PRIOR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_RETURN2: Editor::commands.keys[Keys::RETURN2] = (event.type == SDL_KEYDOWN); break;
                case SDLK_SEPARATOR: Editor::commands.keys[Keys::SEPARATOR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_OUT: Editor::commands.keys[Keys::OUT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_OPER: Editor::commands.keys[Keys::OPER] = (event.type == SDL_KEYDOWN); break;
                case SDLK_CLEARAGAIN: Editor::commands.keys[Keys::CLEARAGAIN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_CRSEL: Editor::commands.keys[Keys::CRSEL] = (event.type == SDL_KEYDOWN); break;
                case SDLK_EXSEL: Editor::commands.keys[Keys::EXSEL] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_00: Editor::commands.keys[Keys::KP_00] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_000: Editor::commands.keys[Keys::KP_000] = (event.type == SDL_KEYDOWN); break;
                case SDLK_THOUSANDSSEPARATOR: Editor::commands.keys[Keys::THOUSANDSSEPARATOR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_DECIMALSEPARATOR: Editor::commands.keys[Keys::DECIMALSEPARATOR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_CURRENCYUNIT: Editor::commands.keys[Keys::CURRENCYUNIT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_CURRENCYSUBUNIT: Editor::commands.keys[Keys::CURRENCYSUBUNIT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_LEFTPAREN: Editor::commands.keys[Keys::KP_LEFTPAREN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_RIGHTPAREN: Editor::commands.keys[Keys::KP_RIGHTPAREN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_LEFTBRACE: Editor::commands.keys[Keys::KP_RIGHTBRACE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_TAB: Editor::commands.keys[Keys::KP_TAB] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_BACKSPACE: Editor::commands.keys[Keys::KP_BACKSPACE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_A: Editor::commands.keys[Keys::KP_LETTER_A] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_B: Editor::commands.keys[Keys::KP_LETTER_B] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_C: Editor::commands.keys[Keys::KP_LETTER_C] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_D: Editor::commands.keys[Keys::KP_LETTER_D] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_E: Editor::commands.keys[Keys::KP_LETTER_E] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_F: Editor::commands.keys[Keys::KP_LETTER_F] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_XOR: Editor::commands.keys[Keys::KP_XOR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_POWER: Editor::commands.keys[Keys::KP_POWER] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_LESS: Editor::commands.keys[Keys::KP_LESS] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_GREATER: Editor::commands.keys[Keys::KP_GREATER] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_AMPERSAND: Editor::commands.keys[Keys::KP_AMPERSAND] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_DBLAMPERSAND: Editor::commands.keys[Keys::KP_DBLAMPERSAND] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_VERTICALBAR: Editor::commands.keys[Keys::KP_VERTICALBAR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_DBLVERTICALBAR: Editor::commands.keys[Keys::KP_DBLVERTICALBAR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_COLON: Editor::commands.keys[Keys::KP_COLON] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_HASH: Editor::commands.keys[Keys::KP_HASH] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_SPACE: Editor::commands.keys[Keys::KP_SPACE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_AT: Editor::commands.keys[Keys::KP_AT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_EXCLAM: Editor::commands.keys[Keys::KP_EXCLAM] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_MEMSTORE: Editor::commands.keys[Keys::KP_MEMSTORE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_MEMRECALL: Editor::commands.keys[Keys::KP_MEMRECALL] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_MEMCLEAR: Editor::commands.keys[Keys::KP_MEMCLEAR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_MEMADD: Editor::commands.keys[Keys::KP_MEMADD] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_MEMSUBTRACT: Editor::commands.keys[Keys::KP_MEMSUBTRACT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_MEMMULTIPLY: Editor::commands.keys[Keys::KP_MEMMULTIPLY] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_MEMDIVIDE: Editor::commands.keys[Keys::KP_MEMDIVIDE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_PLUSMINUS: Editor::commands.keys[Keys::KP_PLUSMINUS] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_CLEAR: Editor::commands.keys[Keys::KP_CLEAR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_CLEARENTRY: Editor::commands.keys[Keys::KP_CLEARENTRY] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_BINARY: Editor::commands.keys[Keys::KP_BINARY] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_OCTAL: Editor::commands.keys[Keys::KP_OCTAL] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_DECIMAL: Editor::commands.keys[Keys::KP_DECIMAL] = (event.type == SDL_KEYDOWN); break;
                case SDLK_KP_HEXADECIMAL: Editor::commands.keys[Keys::KP_HEXADECIMAL] = (event.type == SDL_KEYDOWN); break;
                case SDLK_LCTRL: Editor::commands.keys[Keys::LCTRL] = (event.type == SDL_KEYDOWN); break;
                case SDLK_LSHIFT: Editor::commands.keys[Keys::LSHIFT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_LALT: Editor::commands.keys[Keys::LALT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_LGUI: Editor::commands.keys[Keys::LGUI] = (event.type == SDL_KEYDOWN); break;
                case SDLK_RCTRL: Editor::commands.keys[Keys::F1] = (event.type == SDL_KEYDOWN); break;
                case SDLK_RSHIFT: Editor::commands.keys[Keys::RSHIFT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_RALT: Editor::commands.keys[Keys::RALT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_RGUI: Editor::commands.keys[Keys::RGUI] = (event.type == SDL_KEYDOWN); break;
                case SDLK_MODE: Editor::commands.keys[Keys::MODE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AUDIONEXT: Editor::commands.keys[Keys::AUDIONEXT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AUDIOPREV: Editor::commands.keys[Keys::AUDIOPREV] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AUDIOSTOP: Editor::commands.keys[Keys::AUDIOSTOP] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AUDIOPLAY: Editor::commands.keys[Keys::AUDIOPLAY] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AUDIOMUTE: Editor::commands.keys[Keys::AUDIOMUTE] = (event.type == SDL_KEYDOWN); break;
                case SDLK_MEDIASELECT: Editor::commands.keys[Keys::MEDIASELECT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_WWW: Editor::commands.keys[Keys::WWW] = (event.type == SDL_KEYDOWN); break;
                case SDLK_MAIL: Editor::commands.keys[Keys::MAIL] = (event.type == SDL_KEYDOWN); break;
                case SDLK_CALCULATOR: Editor::commands.keys[Keys::CALCULATOR] = (event.type == SDL_KEYDOWN); break;
                case SDLK_COMPUTER: Editor::commands.keys[Keys::COMPUTER] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AC_SEARCH: Editor::commands.keys[Keys::AC_SEARCH] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AC_HOME: Editor::commands.keys[Keys::AC_HOME] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AC_BACK: Editor::commands.keys[Keys::AC_BACK] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AC_FORWARD: Editor::commands.keys[Keys::AC_FORWARD] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AC_STOP: Editor::commands.keys[Keys::AC_STOP] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AC_REFRESH: Editor::commands.keys[Keys::AC_REFRESH] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AC_BOOKMARKS: Editor::commands.keys[Keys::AC_BOOKMARKS] = (event.type == SDL_KEYDOWN); break;
                case SDLK_BRIGHTNESSDOWN: Editor::commands.keys[Keys::BRIGHTNESSDOWN] = (event.type == SDL_KEYDOWN); break;
                case SDLK_BRIGHTNESSUP: Editor::commands.keys[Keys::BRIGHTNESSUP] = (event.type == SDL_KEYDOWN); break;
                case SDLK_EJECT: Editor::commands.keys[Keys::EJECT] = (event.type == SDL_KEYDOWN); break;
                case SDLK_SLEEP: Editor::commands.keys[Keys::SLEEP] = (event.type == SDL_KEYDOWN); break;
                case SDLK_APP1: Editor::commands.keys[Keys::APP1] = (event.type == SDL_KEYDOWN); break;
                case SDLK_APP2: Editor::commands.keys[Keys::APP2] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AUDIOREWIND: Editor::commands.keys[Keys::AUDIOREWIND] = (event.type == SDL_KEYDOWN); break;
                case SDLK_AUDIOFASTFORWARD: Editor::commands.keys[Keys::AUDIOFASTFORWARD] = (event.type == SDL_KEYDOWN); break;

            }

            for (std::uint16_t i{0};i<240;i++) if (Editor::commands.keys[Keys(i)] && event.type == SDL_KEYDOWN && !Editor::commands.keys_once[Keys(i)]) Editor::commands.keys_once[Keys(i)] = true; // Pas tout à fait au point...

	break;

	default:
	break;

    }

}

void UpdateMouse(const SDL_Event &event) noexcept {

    switch(event.type) {

        case SDL_MOUSEBUTTONDOWN:
        Editor::commands.mouse[event.button.button] = true;
        break;

        case SDL_MOUSEBUTTONUP:
        Editor::commands.mouse[event.button.button] = false;
        break;

        case SDL_MOUSEMOTION:
        Editor::commands.mouse_pos[0] = event.motion.x;
        Editor::commands.mouse_pos[1] = event.motion.y;
        Editor::commands.mouse_pos[2] = event.motion.xrel;
        Editor::commands.mouse_pos[3] = event.motion.yrel;
        break;

        case SDL_MOUSEWHEEL:
        Editor::commands.wheel = event.wheel.y;
        break;

        default:
        //Editor::mousePos[2] = 0;
        //Editor::mousePos[3] = 0;
        //Editor::wheel = 0;
        break;

    }

    if (event.type != SDL_MOUSEMOTION) {

        Editor::commands.mouse_pos[2] = 0;
        Editor::commands.mouse_pos[3] = 0;

    }

    if (event.type != SDL_MOUSEWHEEL) Editor::commands.wheel = 0;

}
