#ifndef CHECKERS_CONSOLE_MAN_H
#define CHECKERS_CONSOLE_MAN_H

#include "piece.h"

class Man: public Piece {
public:
    int move(int to);

    char print_itself();

    // later private

    int calculate_distance_squares(int row, int distance);
    int calculate_distance(int to);
    int calculate_distance_rows(int row, int to);

//    int[] & return_adjacent_squares(int square) {

//    }

//    vector <int> generate_valid_moves();
    vector <int> generate_moves_proposal();
    vector<std::tuple<int, int>> generate_captures_proposal();

    //public
    vector<int> get_valid_moves();

    Man(Color color_, int location_);
    ~Man();
};

#endif //CHECKERS_CONSOLE_MAN_H
