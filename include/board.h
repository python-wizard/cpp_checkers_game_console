#ifndef CHECKERS_CONSOLE_BOARD_H
#define CHECKERS_CONSOLE_BOARD_H

#include "piece.h"

class Board {
    char squares[31];
    int size = 8;

//    typedef Piece* AntPtr;
//    AntPtr * ants = new AntPtr[num_ants];
//

//    Piece *squares_of_pieces[32];
    int initiate_pieces_array();
    int check_space_empty(int location);

    int check_move_in_valid_moves(int to, int* valid_moves, int size);

public:
    void print_board();
    void print_squares();
    int move_piece(int from, int to);
//    int calculate_distance(int from, int to);
//    int try_move(int from, int to);


    // move to private later
    Piece *squares_of_pieces[32];
    int whole_move_procedure(int from, int to);
    Board();

};


#endif //CHECKERS_CONSOLE_BOARD_H
