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
    cout << endl;
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

int Board::try_move(int from, int to) {
    int empty_to = check_space_empty(to);
    int empty_from = check_space_empty(from);

    if (empty_to == 0) {
        cout << "For piece at " << from << " can't move to " << to
             << ". The space is not empty. Choose a different square." << endl;
        return -1;
    }
    else if (empty_from == 1) {
        cout << "There is not piece at " << from << " so something that does not exist can't move... :)" << endl;
        return -1;
    }
    else {
        vector<int> moves_proposal;
        vector<int> moves_valid;
        moves_proposal = (squares_of_pieces[from]->generate_moves_proposal());

        for (int &move : moves_proposal) {
            std::cout << "valid move maybe: " << move << endl;
            empty_to = check_space_empty(move);
            if (empty_to == 1) {
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

                cout << "Piece from " << from << " successfuly moved to " << to << "." << endl; //  %d.", from, to);
                return 1;
            }
        }

        cout << "For piece at " << from << " can't move to " << to << ", it's not a valid move.";
    }
    return 0;
}

int Board::try_capture(int from, int to) {
    int empty_a, empty_b;
    int right_target = 0;
    int non_empty_a = 0;
    vector<std::tuple<int, int>> capture_proposal;
    vector<std::tuple<int, int>> captures_valid;

    if (squares_of_pieces[from] != NULL) {
        capture_proposal = squares_of_pieces[from]->generate_captures_proposal();
    }
    else {
        cout << "These is somthing wrong with the pointer. There is no pointer at this place of the squares_of_pieces array." << endl;
        return -1;
    }

//    vector<int> captures_valid;

    for (auto&& tuple: capture_proposal) {

        int a, b;
        std::tie(a, b) = tuple;
        std::cout << a << " " << b << " " << std::endl;

        empty_a = check_space_empty(a);
        empty_b = check_space_empty(b);

        if (b==to) {
            right_target = 1;
        }

        if (empty_a == 0 && empty_b == 1) {
            Color color_from, color_through;
            color_through = squares_of_pieces[a]->get_color();
            color_from = squares_of_pieces[from]->get_color();

            string str_color_trough;
            string str_color_from;

            if (color_through== black) {
                str_color_trough = "black";
            }
            else {
                str_color_trough = "white";
            }

            if (color_from == black) {
                str_color_from = "black";
            }
            else {
                str_color_from = "white";
            }

            if (color_through != color_from) {
                //            captures_valid.push_back(b);
                captures_valid.push_back(std::make_tuple(a, b));

                //            tuples_move_capture.push_back(std::make_tuple(location_new1, location_new2));
                cout << "valid capture from (" << str_color_from << ") : " << from << " to: (" << str_color_trough << ") " << b << endl;

            }
            else {
                cout << "Trying to remove one's own piece... :)"<< endl;
            }

        }
        else {
            cout << "captures from " << from << "not a valid capture " << " to: " << b << "   a_empty: " << empty_a << "   b_empty" << empty_b << endl;
            cout << "You capture by jumping one square over enemy's piece, meaning you move two squares." << endl;
        }
    }

    for (auto&& tuple: captures_valid) {
        int a, b;
        std::tie(a, b) = tuple;

        if (b == to) {
            if (squares_of_pieces[b] == NULL && squares_of_pieces[a] != NULL) {
                squares_of_pieces[to] = squares_of_pieces[from];
                squares_of_pieces[from]->move(from, to);
                squares_of_pieces[from] = NULL;

                //deleting
                delete squares_of_pieces[a];
                squares_of_pieces[a] = NULL;

            } else {
                cout << "Something went wrong with a pointer";
            }

            cout << "Piece from " << from << " successfuly moved to " << to << ". ";
            cout << "And captured at square " << a << " which was removed from the board.";//  %d.", from, to);
            return 1;
        }
    }

    if (right_target==0) {
        cout << "You cannot move capture from " << from << " to " << to << " Wrong target.";
    }

    return 0;
}

int Board::whole_move_procedure(int from, int to) {
    int moved = try_move(from, to);

    if (moved == 1) {
        return 1;
    }
    else if (moved == -1) {
        // something went wrong
        return -1;
    }

    // check capture
    int captured = try_capture(from, to);
    return captured;

}

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
}