#include "../include/man.h"

vector <int> Man::generate_moves_proposal() {

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

//
//    if (color == black) {
//        if (row == 7) {
//            valid_moves[0] = '\0';
//            valid_moves[1] = '\0';
//        }
//        else {
//            if (row%2 == 0) {
////            if (column == 0) {
////                moves_array[0] = location + 5;
////                moves_array[1] = '\0';
////            }
////            else
//                if (column == 7) {
//                    valid_moves[0] = location + 4;
//                    valid_moves[1] = '\0';
//                }
//                else {
//                    valid_moves[0] = location + 4;
//                    valid_moves[1] = location + 5;
//                }
//            }
//            else {
//                if (column == 0) {
//                    valid_moves[0] = location + 4;
//                    valid_moves[1] = NULL;
//                }
////            else if (column == 8) {
////                moves_array[0] = location + 4;
////                moves_array[1] = NULL;
////            }
//                else {
//                    valid_moves[0] = location + 3;
//                    valid_moves[1] = location + 4;
//                }
//            }
//        }
//
//    }
////    return moves_array;
//}

//int Man::generate_valid_moves() {
//    int row = calculate_row(location);
//    int column = calculate_column(location);
////    int moves_array[2];
//
//    if (color == black) {
//        if (row == 7) {
//            valid_moves[0] = '\0';
//            valid_moves[1] = '\0';
//        }
//        else {
//            if (row%2 == 0) {
////            if (column == 0) {
////                moves_array[0] = location + 5;
////                moves_array[1] = '\0';
////            }
////            else
//                if (column == 7) {
//                    valid_moves[0] = location + 4;
//                    valid_moves[1] = '\0';
//                }
//                else {
//                    valid_moves[0] = location + 4;
//                    valid_moves[1] = location + 5;
//                }
//            }
//            else {
//                if (column == 0) {
//                    valid_moves[0] = location + 4;
//                    valid_moves[1] = NULL;
//                }
////            else if (column == 8) {
////                moves_array[0] = location + 4;
////                moves_array[1] = NULL;
////            }
//                else {
//                    valid_moves[0] = location + 3;
//                    valid_moves[1] = location + 4;
//                }
//            }
//        }
//
//    }
////    return moves_array;
//}

vector<int> Man::get_valid_moves() {
    return valid_moves;
}

int Man::calculate_distance(int to) {
    return location - to;
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
