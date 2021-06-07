#ifndef CHECKERS_CONSOLE_PIECE_H
#define CHECKERS_CONSOLE_PIECE_H

#include <iostream>
#include <vector>
#include <tuple>
#include "other.h"
using namespace std;

class Piece {
protected:
    int location;
    int loc_row;
    int loc_col;
    int history[30];
    Color color;
    std::vector<int> valid_moves;

    int add_history(int location_);
    virtual int * return_valid_moves(int *moves_array) {};
    virtual int generate_valid_moves() {};

    int calculate_distance_squares(int row, int distance);
    int calculate_distance(int to);
    int calculate_distance_rows(int row, int to);
    vector<int> get_valid_moves();

public:
    Color get_color();
    int get_location();
    virtual char return_descriptive_char();

    // functions responsible for movement
    virtual vector<int> generate_possible_moves() {}
    int move(int from, int to);
    virtual vector<std::tuple<int, int>> generate_possible_captures() {};

    // calculating row and columns
    int calculate_row(int square);
    int calculate_column(int square);
    int calculate_location(int row, int column);

//    int Man::generate_valid_moves



    // old
    void print_valid_moves();

    // constructors
    Piece(Color color_, int location_);

};

#endif //CHECKERS_CONSOLE_PIECE_H
