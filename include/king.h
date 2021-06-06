#ifndef CHECKERS_CONSOLE_KING_H
#define CHECKERS_CONSOLE_KING_H

#include "piece.h"

class King: public Piece {
public:
//    int move(int to);
//
    char return_descriptive_char();

    // later private

//    int calculate_distance_squares(int row, int distance);
//    int calculate_distance(int to);
//    int calculate_distance_rows(int row, int to);

//    int[] & return_adjacent_squares(int square) {

//    }

//    vector <int> generate_valid_moves();
//    vector <int> generate_moves_proposal();
//    vector<std::tuple<int, int>> generate_captures_proposal();

    //public
//    vector<int> get_valid_moves();

    King(Color color_, int location_);
    ~King();
};

#endif //CHECKERS_CONSOLE_KING_H
