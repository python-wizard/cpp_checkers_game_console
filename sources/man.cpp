#include <tuple>
#include "../include/man.h"


// default constructor
Man::Man(Color color_, int location_): Piece(color_, location_) {

}

// return letter describing piece to be used by print_board() function
char Man::return_descriptive_char() {
    if (color == black) {
//        putchar('b');
        return 'b';
    }
    else if (color == white) {
//        putchar('w');
        return 'w';
    }
}

// default destructor
Man::~Man() {

};

// function responsible for returning all legal moves - not captures
vector <int> Man::generate_possible_moves() {

    std::vector<int> moves_proposal;

    int row = calculate_row(location);
    int column = calculate_column(location);

    int color_offset;
    if (color == black) {
        if (row >= 7) {
            cout << "Something's wrong, the pawn is already a King." << endl;
        }

        color_offset = 1;
    }
    else {
        color_offset = -1;
    }

    int row_new, col_new, location_new;

    if (column != 0) {
        row_new = row + color_offset;
        col_new = column - 1;
        location_new = calculate_location(row_new, col_new);
        //append vector;

        moves_proposal.push_back(location_new);

    }

    if (column != 7) {
        row_new = row + color_offset;
        col_new = column + 1;
        location_new = calculate_location(row_new, col_new);
        //append vector;
        moves_proposal.push_back(location_new);
    }

    return moves_proposal;
}

// function responsible for returning all legal captures
vector<std::tuple<int, int>> Man::generate_possible_captures() {

    std::vector<std::tuple<int, int>> tuples_move_capture;

    int row = calculate_row(location);
    int column = calculate_column(location);

    int color_offset;
    if (color == black) {
        if (row >= 7) {
            cout << "Something's wrong, the pawn is already a King." << endl;
        }

        color_offset = 1;
    }
    else {
        color_offset = -1;
    }

    int row_new1, col_new1, location_new1;
    int row_new2, col_new2, location_new2;


    if (column > 1) {
        row_new1 = row + color_offset;
        col_new1 = column - 1;
        location_new1 = calculate_location(row_new1, col_new1);

        row_new2 = row + (color_offset*2);
        col_new2 = column - 2;
        location_new2 = calculate_location(row_new2, col_new2);

        //append vector;

        tuples_move_capture.push_back(std::make_tuple(location_new1, location_new2));

    }

    if (column < 6) {

        row_new1 = row + color_offset;
        col_new1 = column + 1;
        location_new1 = calculate_location(row_new1, col_new1);

        row_new2 = row + (color_offset*2);
        col_new2 = column + 2;
        location_new2 = calculate_location(row_new2, col_new2);

        //append vector;

        tuples_move_capture.push_back(std::make_tuple(location_new1, location_new2));

    }

    return tuples_move_capture;
}


