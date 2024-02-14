#include "isChar.hpp"

//Checks if a character is an alphabet character.
bool isChar(char ch) {
    int int_ch = (int)ch;

    if ((65 <= int_ch && int_ch <= 90) || (97 <= int_ch && int_ch <= 122)) {
        return true;
    }

    else {
        return false;
    }
}