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

int Piece::calculate_row(int square) {
    int row = square/4;
    return row;
}

int Piece::calculate_column(int square) {
    int column;
    int rem_8 = square%8;

    if (rem_8 <=3) {
        column = rem_8 * 2 + 1;
    }
    else {
        column = (rem_8-4) * 2;
    }
    return column;
}