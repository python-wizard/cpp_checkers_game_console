#include "../include/piece.h"



Piece::Piece(Color color_, int location_) {
    color = color_;
    location = location_;
    add_history(location);
}

int Piece::move(int from, int to) {
    location = to;
    add_history(to);

    return 0;
}

char Piece::print_itself() {
    return 'p';
    cout << "printing piece";


};
