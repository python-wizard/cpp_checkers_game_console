//#include <iostream>
#include <stdio.h>
#include <string.h>
//using namespace std;
//#include <stdlib.h>

enum Color {black, white};

void clean_array(int *array) {
    int i;
    for (i=0; i<10; i++) {
        int size = sizeof array / sizeof *array;
        memset(array, 0, size);
    }
}

class Piece {
protected:
    int location;
    int history[30];
    Color color;

    int add_history(int location_) {
        int i = 0;
        while (history[i] != '\0') {
            history[i] = location_;
        }
    }
public:
    int move(int from, int to);
    Piece(Color color_, int location_);
    virtual char print_itself();

    // move to protected later
    virtual int * return_valid_moves(int *moves_array) {};

};

Piece::Piece(Color color_, int location_) {
    color = color_;
    location = location_;
    add_history(location);
}

int Piece::move(int from, int to) {
    location = to;
    add_history(to);

    return 0;
}

char Piece::print_itself() {
    return 'p';
    printf("printing piece");


};


class Man: public Piece {
public:
    int move(int to);

    char print_itself();

    // later private
    int calculate_row(int square);
    int calculate_distance_squares(int row, int distance);
    int calculate_distance(int to);
    int calculate_distance_rows(int row, int to);
    int calculate_column(int square);
//    int[] & return_adjacent_squares(int square) {

//    }

    int * return_valid_moves(int *moves_array);

    Man(Color color_, int location_);
    ~Man();
};

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

class Board {
    char squares[31];
    int size = 8;

//    typedef Piece* AntPtr;
//    AntPtr * ants = new AntPtr[num_ants];
//

//    Piece *squares_of_pieces[32];
    int initiate_pieces_array();
    int check_space_empty(int location);
    void print_valid_moves(int *valid_moves, int size);
    int check_move_in_valid_moves(int to, int* valid_moves, int size);

public:
    void print_board();
    void print_squares();
    int move_piece(int from, int to);
//    int calculate_distance(int from, int to);
//    int try_move(int from, int to);


    // move to private later
    Piece *squares_of_pieces[32];

    Board();

};

//int Board::try_move(int from, int to) {
////    int result = squares_of_pieces[from]->move();
//}



Board::Board() {
    initiate_pieces_array();
}

int Board::check_space_empty(int location) {
    if (location < 0 || location > 31) {
        printf("Wrong space number.");
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
    int i, j=0;
    for (i=0; i<32; i++) {
        if ((j%2) ==1) {
            printf("   ");
        }

        if (squares_of_pieces[i] == NULL) {
            printf("%5d", i);
        }
        else {
            char piece = squares_of_pieces[i]->print_itself();
            printf("%5c", piece);
        }


        if ((j%2) == 0) {
            printf("   ");
        }
        if ((i%4) == 3) {
            j++;
            putchar('\n');
        }
    }
}

void Board::print_squares() {
    int i, j=0;
    for (i=0; i<32; i++) {
        if ((j%2) ==1) {
            printf("   ");
        }
        printf("%5d", i);
        if ((j%2) == 0) {
            printf("   ");
        }
        if ((i%4) == 3) {
            j++;
            putchar('\n');
        }
    }
}

void Board::print_valid_moves(int *valid_moves, int size) {
    int i;
    for (i=0; i<size; i++) {
        if (valid_moves[i] != NULL) {
            printf("%d ", valid_moves[i]);
        }

    }

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
        printf("For piece at %d can't move to %d. The space is not empty. Choose a different square.", from, to);
        return 0;
    }

    else {
        int valid_moves[8];
        clean_array(valid_moves);
        squares_of_pieces[from]->return_valid_moves(valid_moves);
        print_valid_moves(valid_moves, 8);
        int valid_move = check_move_in_valid_moves(to, valid_moves, 8);

        if (valid_move == 1) {

            if (squares_of_pieces[to] == NULL) {
                squares_of_pieces[to] = squares_of_pieces[from];
                squares_of_pieces[from]->move(from, to);
                squares_of_pieces[from] = NULL;

            }
            else {
                printf("Something went wrong with a pointer");
            }
            printf("Piece from %d successfuly moved to %d.", from, to);
        }
        else {
            printf("For piece at %d can't move to %d, it's not a valid move", from, to);
        }

    }





//    int distance = calculate_distance(from, to);
    // calculate distance
    // check distance

    //move piece - call move on piece
}

//void clean_array(char *array) {
//    int i;
//    for (i=0; i<10; i++) {
//        memset(array, 0, strlen(array));
//    }
//}



int main() {
//    std::cout << "Hello, World!" << std::endl;

    Board board1;
    board1.print_board();

    board1.move_piece(8,12);


//    int p[2];
//    int j;
//
//    for (j=0; j<32; j++) {
//        printf("Square %d :", j);
//        board1.squares_of_pieces[j]->return_valid_moves(p);
//        int i;
//        int size = sizeof p / sizeof *p;
////    printf("Sizeof: %d  ", size);
//
//        for (i=0; i<size; i++) {
//            if (p[i] != '\0') {
//                printf("%d  ", p[i]);
//            }
//
//        }
//        putchar('\n');
//    }


//    printf("%d  ", p[0]);
//    printf("%d  ", p[1]);


//
//    printf("%d", p[i]);
//    for


//    int i;
//    for (i=0; i<34; i++) {
//        int empty = board1.check_space_empty(i);
//        printf("%d", empty);
////        putchar('\n');
//    }

//    int dis = board1.calculate_distance(0, 4);
//    printf("%d", dis);

    return 0;

}
