//
// Created by ala on 13/09/2020.
//

#ifndef APPKIT_KEYBOARD_EVENTS_T_H
#define APPKIT_KEYBOARD_EVENTS_T_H

#include "KeyboardListener.h"
#include "vector"

using namespace std;

class KeyboardEvents {
private:
    vector<KeyboardListener*> keyboardListeners;
public:
    void registerListener(KeyboardListener *keyboardListener);

    void listen();
};


#endif //APPKIT_KEYBOARD_EVENTS_T_H
