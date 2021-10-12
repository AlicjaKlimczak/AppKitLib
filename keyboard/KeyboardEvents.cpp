//
// Created by ala on 13/09/2020.
//

#include "KeyboardEvents.h"
#include "SDL.h"

void KeyboardEvents::registerListener(KeyboardListener *listener) {
    keyboardListeners.push_back(listener);
}

void KeyboardEvents::listen() {
    SDL_PumpEvents();
    const Uint8 *keyboard_state = const_cast <Uint8*>(SDL_GetKeyboardState(nullptr));
    for (KeyboardListener *listener : keyboardListeners) {
        listener->reactToKeyboardEvent(keyboard_state);
    }
}
