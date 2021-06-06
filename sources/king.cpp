#include "../include/king.h"

King::King(Color color_, int location_): Piece(color_, location_) {

}

char King::return_descriptive_char() {
    if (color == black) {
//        putchar('b');
        return 'B';
    }
    else if (color == white) {
//        putchar('w');
        return 'W';
    }
}

King::~King() = default;;