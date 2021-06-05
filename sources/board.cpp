#include "../include/board.h"
#include "../include/man.h"
#include <iomanip>

Board::Board() {
    initiate_pieces_array();
}

int Board::check_space_empty(int location) {
    if (location < 0 || location > 31) {
        cout << "Wrong space number.";
        return -1;
    }
    else {
        if (squares_of_pieces[location] == NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }
}



//int Board::try_move(int from, int to) {
////    int result = squares_of_pieces[from]->move();
//}



int Board::initiate_pieces_array() {
    Man *man_temp_pointer;
    Piece *piece_temp_pointer;
    //initiate black
    int i;
    for (i=0; i<12; i++) {
//        man_temp_pointer =
        squares_of_pieces[i] = new Man(black, i);
    }
    for (;i<20; i++) {
        squares_of_pieces[i] = NULL;
    }
    for (; i<32; i++) {
        squares_of_pieces[i] = new Man(white, i);
    }
}

void Board::print_board() {
    cout << "     0     1     2     3     4     5     6     7    \n";

    int i, j=0;
    for (i=0; i<32; i++) {
        if ((i%4)==0) {
            cout << "  +-----------------------------------------------+\n";
            cout << i/4 << " |";
        }

        if ((j%2) ==0) {
            cout << "     |";
        }

        if (squares_of_pieces[i] == NULL) {
            cout << setw(4)  << i << " |" ;//    << 1 << endl;

//            cout << format("%1% %2% %|40t|%3%\n") i << "   |"; //"%5d|
        }
        else {
            char piece = squares_of_pieces[i]->print_itself();
            cout << setw(4)  << piece << " |" ;//    << 1 << endl;
//            cout << piece << "    |"; //"%5c|", );
        }


        if ((j%2) == 1) {
            cout << "     |";
        }
        if ((i%4) == 3) {
            j++;
            putchar('\n');
        }
    }
    cout << "  +-----------------------------------------------+\n";
}

void Board::print_squares() {
    int i, j=0;
    for (i=0; i<32; i++) {
        if ((j%2) ==1) {
            cout << "   ";
        }
//        printf("%5d", i);
        cout << setw(5) << i;
        if ((j%2) == 0) {
            cout << "   ";
        }
        if ((i%4) == 3) {
            j++;
            putchar('\n');
        }
    }
}

int Board::whole_move_procedure(int from, int to) {
    int empty = check_space_empty(to);

    if (empty == 0) {
        cout << "For piece at " << from << " can't move to " << to
             << ". The space is not empty. Choose a different square." << endl;
        return 0;
    } else {
        vector<int> moves_proposal;
        vector<int> moves_valid;
        moves_proposal = (squares_of_pieces[from]->generate_moves_proposal());

        for (int &move : moves_proposal) {
            std::cout << "valid move maybe: " << move << endl;
            empty = check_space_empty(move);
            if (empty == 1) {
                moves_valid.push_back(move);
                std::cout << "valid move : " << move << endl;
            }
        }
        std::cout << '\n';
        for (int &move_valid : moves_valid) {
            if (move_valid == to) {
                if (squares_of_pieces[to] == NULL) {
                    squares_of_pieces[to] = squares_of_pieces[from];
                    squares_of_pieces[from]->move(from, to);
                    squares_of_pieces[from] = NULL;

                } else {
                    cout << "Something went wrong with a pointer";
                }

                cout << "Piece from " << from << " successfuly moved to " << to << "."; //  %d.", from, to);
                return 1;
            }
        }


        cout << "For piece at " << from << " can't move to " << to << ", it's not a valid move.";
    }
    // check capture
    std::vector<std::tuple<int, int>> tuples_move_capture;


}
//        print_valid_moves(valid_moves, 8);
//        int valid_move = check_move_in_valid_moves(to, valid_moves, 8);
//
//        if (valid_move == 1) {
//
//            if (squares_of_pieces[to] == NULL) {
//                squares_of_pieces[to] = squares_of_pieces[from];
//                squares_of_pieces[from]->move(from, to);
//                squares_of_pieces[from] = NULL;
//
//            }
//            else {
//                cout << "Something went wrong with a pointer";
//            }
//            cout << "Piece from " << from << " successfuly moved to " << to << "."; //  %d.", from, to);
//        }
//        else {
//            cout << "For piece at " << from << " can't move to " << to << ", it's not a valid move.";
////            cout << "For piece at %d can't move to %d, it's not a valid move", from, to);
//        }
//
//    }
//
//}


int Board::check_move_in_valid_moves(int to, int* valid_moves, int size) {
    int i;
    int destination_in_valid_moves = 0;
    for (i=0; i<size; i++) {
        if (valid_moves[i] == to) {
            destination_in_valid_moves = 1;
            return destination_in_valid_moves;
        }
    }

    return destination_in_valid_moves;
}

int Board::move_piece(int from, int to) {
    int empty = check_space_empty(to);

    if (empty == 0) {
        cout << "For piece at %d can't move to %d. The space is not empty. Choose a different square.", from, to;
        return 0;
    }
//
//    else {
//        int valid_moves[8];
//        clean_array(valid_moves);
//        return_valid_moves(valid_moves);
//
//        print_valid_moves(valid_moves, 8);
//        int valid_move = check_move_in_valid_moves(to, valid_moves, 8);
//
//        if (valid_move == 1) {
//
//            if (squares_of_pieces[to] == NULL) {
//                squares_of_pieces[to] = squares_of_pieces[from];
//                squares_of_pieces[from]->move(from, to);
//                squares_of_pieces[from] = NULL;
//
//            }
//            else {
//                cout << "Something went wrong with a pointer";
//            }
//            cout << "Piece from " << from << " successfuly moved to " << to << "."; //  %d.", from, to);
//        }
//        else {
//            cout << "For piece at " << from << " can't move to " << to << ", it's not a valid move.";
////            cout << "For piece at %d can't move to %d, it's not a valid move", from, to);
//        }

//    }





//    int distance = calculate_distance(from, to);
    // calculate distance
    // check distance

    //move piece - call move on piece
}
