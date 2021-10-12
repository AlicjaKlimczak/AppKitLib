//
// Created by ala on 13/09/2020.
//

#ifndef APPKIT_GAME_EXCEPTION_T_H
#define APPKIT_GAME_EXCEPTION_T_H

#include "exception"

using namespace std;

class GameException : public exception {
private:
    const char* message;
public:
    explicit GameException(const char *message);
    const char* what() const noexcept override;
};


#endif //APPKIT_GAME_EXCEPTION_T_H
