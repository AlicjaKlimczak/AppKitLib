//
// Created by ala on 13/09/2020.
//

#include "GameException.h"

GameException::GameException(const char *message) {
    this->message = message;
}

const char *GameException::what() const noexcept {
    return message;
}
