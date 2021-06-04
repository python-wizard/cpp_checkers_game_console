#ifndef CHECKERS_CONSOLE_MAN_H
#define CHECKERS_CONSOLE_MAN_H

#include "piece.h"

class Man: public Piece {
public:
    int move(int to);

    char print_itself();

    // later private
    int calculate_row(int square);
    int calculate_distance_squares(int row, int distance);
    int calculate_distance(int to);
    int calculate_distance_rows(int row, int to);
    int calculate_column(int square);
//    int[] & return_adjacent_squares(int square) {

//    }

    int * return_valid_moves(int *moves_array);

    Man(Color color_, int location_);
    ~Man();
};


#endif //CHECKERS_CONSOLE_MAN_H
