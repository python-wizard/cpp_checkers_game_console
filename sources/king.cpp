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

vector <int> King::generate_possible_moves() {

    std::vector<int> moves_proposal;

    int row = calculate_row(location);
    int column = calculate_column(location);
    int row_new, col_new, location_new;

    if (row >= 0 && row < 7) {
        if (column > 0) {
            row_new = row + 1;
            col_new = column - 1;
            location_new = calculate_location(row_new, col_new);
            //append vector;
            moves_proposal.push_back(location_new);
        }

        if (column < 7) {
            row_new = row + 1;
            col_new = column + 1;
            location_new = calculate_location(row_new, col_new);
            //append vector;
            moves_proposal.push_back(location_new);
        }
    }

    if (row > 0 && row <= 7) {
        if (column > 0) {
            row_new = row - 1;
            col_new = column - 1;
            location_new = calculate_location(row_new, col_new);
            //append vector;
            moves_proposal.push_back(location_new);
        }

        if (column < 7) {
            row_new = row - 1;
            col_new = column + 1;
            location_new = calculate_location(row_new, col_new);
            //append vector;
            moves_proposal.push_back(location_new);
        }
    }


    return moves_proposal;
}

vector<std::tuple<int, int>> King::generate_possible_captures() {

    std::vector<std::tuple<int, int>> tuples_move_capture;

    int row = calculate_row(location);
    int column = calculate_column(location);

//    int color_offset;
//    if (color == black) {
//        if (row >= 7) {
//            cout << "Something's wrong, the pawn is already a King." << endl;
//        }
//
//        color_offset = 1;
//    }
//    else {
//        color_offset = -1;
//    }

    int row_new1, col_new1, location_new1;
    int row_new2, col_new2, location_new2;


    if (column > 1 && column <=7) {
        if (row <6 && row >=0) {
            row_new1 = row + 1;
            col_new1 = column - 1;
            location_new1 = calculate_location(row_new1, col_new1);

            row_new2 = row + 2;
            col_new2 = column - 2;
            location_new2 = calculate_location(row_new2, col_new2);

            //append vector;

            tuples_move_capture.push_back(std::make_tuple(location_new1, location_new2));
        }
        if (row > 1 && row <=7) {
            row_new1 = row - 1;
            col_new1 = column - 1;
            location_new1 = calculate_location(row_new1, col_new1);

            row_new2 = row - 2;
            col_new2 = column - 2;
            location_new2 = calculate_location(row_new2, col_new2);

            //append vector;

            tuples_move_capture.push_back(std::make_tuple(location_new1, location_new2));
        }
    }

    if (column < 6 && column >= 0) {
        if (row <6 && row >=0) {
            row_new1 = row + 1;
            col_new1 = column + 1;
            location_new1 = calculate_location(row_new1, col_new1);

            row_new2 = row + 2;
            col_new2 = column + 2;
            location_new2 = calculate_location(row_new2, col_new2);

            //append vector;

            tuples_move_capture.push_back(std::make_tuple(location_new1, location_new2));
        }
        if (row > 1 && row <=7) {
            row_new1 = row - 1;
            col_new1 = column + 1;
            location_new1 = calculate_location(row_new1, col_new1);

            row_new2 = row - 2;
            col_new2 = column + 2;
            location_new2 = calculate_location(row_new2, col_new2);

            //append vector;

            tuples_move_capture.push_back(std::make_tuple(location_new1, location_new2));
        }
    }

    for (auto&& tuple: tuples_move_capture)
    {
        int X, Y;
        std::tie(X, Y) = tuple;

        std::cout << X << " " << Y << " " << std::endl;
    }
    return tuples_move_capture;
}