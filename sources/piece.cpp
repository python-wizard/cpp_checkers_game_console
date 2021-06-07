#include "../include/piece.h"
#include <iomanip>

// constructor
Piece::Piece(Color color_, int location_) {
    color = color_;
    location = location_;
    add_history(location);
}

// function responsible for final moving (changing location and adding to history),
// used by other move functions, mainly in board
int Piece::move(int from, int to) {
    location = to;
    add_history(to);

    return 0;
}

// virtual method returning descriptive char. Because of polimorphism, this version is never invoked
char Piece::return_descriptive_char() {
    return 'p';
    cout << "printing piece";
};

// important function to calculate row based on square number
int Piece::calculate_row(int square) {
    int row = square/4;
    return row;
}

// important function to calculate column based on square number
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

//function printing valid moves
void Piece::print_valid_moves() {

    for (int & valid_move : valid_moves)
        std::cout << ' ' << valid_move;
    std::cout << '\n';
}

// getter function for private or protected color field
Color Piece::get_color() {
    return color;
}

// function returning square number based on row and column
int Piece::calculate_location(int row, int column) {
    int location;

    if (((row+column)%2)==0) {
        cout << " On that row column there is no space. wrong color." << endl;
        return -1;
    }

//    if ((row%2)==0) {
//        if ((location%2)==0) {
//            cout << " On that row column there is no space. wrong color." << endl;
//        }
//    }
//    else {
//        if ((location%2)==1) {
//            cout << " On that row column there is no space. wrong color." << endl;
//        }
//    }

    location = row*4;
    location += column/2;
    return location;
}

// getter function for location field
int Piece::get_location() {
    return location;
}

//function add history to the last field of the history field
int Piece::add_history(int location_) {
    int i = 0;
    while (history[i] != '\0') {
    history[i] = location_;
    }
}

// function calculating distance, it was mainly used in previous move iteration
int Piece::calculate_distance_squares(int row, int distance) {
    int short_jump;
    int long_jump;

    // black move direction
    if (distance > 0) {
    }
    if (row%2 == 0) {
    }
}

// function calculating distance, it was mainly used in previous move iteration
int Piece::calculate_distance_rows(int row, int to) {
    int row_destination = calculate_row(to);
    return row_destination - row;
}
