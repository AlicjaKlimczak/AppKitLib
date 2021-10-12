//
// Created by ala on 13/09/2020.
//

#ifndef APPKIT_KEYBOARD_LISTENER_T_H
#define APPKIT_KEYBOARD_LISTENER_T_H

#include <cstdint>

class KeyboardListener {
public:
    virtual void reactToKeyboardEvent(const uint8_t *keyboard_state) = 0;
};

#endif //APPKIT_KEYBOARD_LISTENER_T_H
