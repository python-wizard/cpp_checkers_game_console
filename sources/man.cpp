#include "../include/man.h"

int * Man::return_valid_moves(int *moves_array) {
    int row = calculate_row(location);
    int column = calculate_column(location);
//    int moves_array[2];

    if (color == black) {
        if (row == 7) {
            moves_array[0] = '\0';
            moves_array[1] = '\0';
        }
        else {
            if (row%2 == 0) {
//            if (column == 0) {
//                moves_array[0] = location + 5;
//                moves_array[1] = '\0';
//            }
//            else
                if (column == 7) {
                    moves_array[0] = location + 4;
                    moves_array[1] = '\0';
                }
                else {
                    moves_array[0] = location + 4;
                    moves_array[1] = location + 5;
                }
            }
            else {
                if (column == 0) {
                    moves_array[0] = location + 4;
                    moves_array[1] = NULL;
                }
//            else if (column == 8) {
//                moves_array[0] = location + 4;
//                moves_array[1] = NULL;
//            }
                else {
                    moves_array[0] = location + 3;
                    moves_array[1] = location + 4;
                }
            }
        }

    }
    return moves_array;
}

int Man::calculate_distance(int to) {
    return location - to;
}

int Man::calculate_row(int square) {
    int row = square/4;
    return row;
}

int Man::calculate_column(int square) {
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

int Man::calculate_distance_squares(int row, int distance) {
    int short_jump;
    int long_jump;

    // black move direction
    if (distance > 0) {

    }

    if (row%2 == 0) {

    }
}

int Man::calculate_distance_rows(int row, int to) {
    int row_destination = calculate_row(to);
    return row_destination - row;
}


//int Man::move(int to) {
//    int row = calculate_row(location);
//    // calculate distance (raw square numbers)
//    int distance = calculate_distance(to);
//
//
//    // calculate distance in rows
//    calculate_distance_rows(row, to);
//
//    //check whether adjacent square
//    calculate_distance_squares(row, distance);
//
//    //
//    return 0;
//}

Man::Man(Color color_, int location_): Piece(color_, location_) {

}

char Man::print_itself() {
    if (color == black) {
//        putchar('b');
        return 'b';
    }
    else if (color == white) {
//        putchar('w');
        return 'w';
    }
}

Man::~Man() {

};
