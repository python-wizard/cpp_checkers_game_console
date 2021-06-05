#ifndef CHECKERS_CONSOLE_PIECE_H
#define CHECKERS_CONSOLE_PIECE_H

#include <iostream>
#include "other.h"
using namespace std;

class Piece {
protected:
    int location;
    int loc_row;
    int loc_col;
    int history[30];
    Color color;

    int add_history(int location_) {
        int i = 0;
        while (history[i] != '\0') {
            history[i] = location_;
        }
    }
public:
    int move(int from, int to);
    Piece(Color color_, int location_);
    virtual char print_itself();

    // move to protected later
    virtual int * return_valid_moves(int *moves_array) {};
    int calculate_row(int square);
    int calculate_column(int square);

};


#endif //CHECKERS_CONSOLE_PIECE_H
