#ifndef CHECKERS_CONSOLE_BOARD_H
#define CHECKERS_CONSOLE_BOARD_H

#include "piece.h"

class Board {
//    char squares[31];
    int size = 8;
    int game_ended = 0;
    Color winner;

//    typedef Piece* AntPtr;
//    AntPtr * ants = new AntPtr[num_ants];
//

//    Piece *squares_of_pieces[32];
    int initiate_pieces_array();
    int check_space_empty(int location);

    int check_move_in_valid_moves(int to, int* valid_moves, int size);
    int promotion(int location, Color color, string str_color);

public:
    void print_board();
    void print_squares();
//    int move_piece(int from, int to);
//    int calculate_distance(int from, int to);
//    int try_move(int from, int to);


    // move to private later
    Piece *squares_of_pieces[32];
    int whole_move_procedure(int from, int to, Color turn);
    int try_capture(int from, int to);
    int try_move(int from, int to);
    int check_player_has_no_pieces();

    int initiate_pieces_from_vector(vector <int> vector_black, vector <int> vector_white,
                                    vector<int> vector_black_king = {}, vector<int> vector_white_king = {});

    int man_to_king_promotion(int location);

    std::tuple<vector<int>, vector<int>> return_locations_pieces_board();
//    vector<std::tuple<int, int>>


    // private proper

    template <typename T>
    char return_char(T piece) {
        cout << "The signs for this class is :";
        char character = piece.return_descriptive_char();
        cout << character << endl;
        return (character);
    }

//    template <typename T>
//    T combine_location(T piece1, T piece2) {
//        int new_location = piece1.get_location() + piece2.get_location();
//        Color col_temp = piece1.get_color();
//        T T_temp(col_temp, new_location);
//        return (T_temp);
//    }

    Board();
    Board(vector <int> vector_black, vector <int> vector_white,
          vector<int> vector_black_king = {}, vector<int> vector_white_king = {});

};

#endif //CHECKERS_CONSOLE_BOARD_H
