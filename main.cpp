#include <iostream>
#include <stdio.h>
#include <string.h>
//using namespace std;
//#include <stdlib.h>

//#include "include/piece.h"
#include "include/board.h"

using namespace std;


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
//    int row = board1.squares_of_pieces[0]->calculate_row(0);
//    cout << "row: " << row;
//
//    int loc = board1.squares_of_pieces[0]->calculate_location(0, 0);
//    cout << "loc 0 0: " << loc;
//
//    loc = board1.squares_of_pieces[0]->calculate_location(0, 1);
//    cout << "loc 0 1: " << loc;
//
//    loc = board1.squares_of_pieces[0]->calculate_location(0, 3);
//    cout << "loc 0 3: " << loc;
//
//    loc = board1.squares_of_pieces[0]->calculate_location(0, 5);
//    cout << "loc 0 5: " << loc;
//
//    loc = board1.squares_of_pieces[0]->calculate_location(0, 7);
//    cout << "loc 0 7: " << loc;
//
//    loc = board1.squares_of_pieces[0]->calculate_location(1, 0);
//    cout << "loc 1 0: " << loc;
//
//    loc = board1.squares_of_pieces[0]->calculate_location(2, 1);
//    cout << "loc 2 1: " << loc;
//
//    loc = board1.squares_of_pieces[0]->calculate_location(7, 7);
//    cout << "loc 7 7: " << loc;
//
//    loc = board1.squares_of_pieces[0]->calculate_location(7, 6);
//    cout << "loc 7 6: " << loc;

//    board1.whole_move_procedure(0, 4);
//    board1.print_board();
//
//    board1.whole_move_procedure(8, 12);
//    board1.print_board();
//
//    board1.whole_move_procedure(12, 16);
//    board1.print_board();
//
//    board1.whole_move_procedure(20, 16);
//    board1.print_board();

//    board1.squares_of_pieces[0]->generate_captures_proposal();
//    board1.squares_of_pieces[1]->generate_captures_proposal();
//    board1.squares_of_pieces[3]->generate_captures_proposal();
//    board1.squares_of_pieces[27]->generate_captures_proposal();
//    board1.squares_of_pieces[28]->generate_captures_proposal();
//    board1.squares_of_pieces[29]->generate_captures_proposal();


    board1.whole_move_procedure(8, 13);
//    board1.print_board();
//
    board1.whole_move_procedure(13, 17);
//    board1.print_board();

    board1.whole_move_procedure(4, 8);
//    board1.print_board();
//
    board1.whole_move_procedure(8, 12);

    board1.whole_move_procedure(9, 13);
    board1.whole_move_procedure(13, 16);
//    board1.print_board();

    board1.whole_move_procedure(23, 19);
//    board1.print_board();
//
    board1.whole_move_procedure(19, 15);

    board1.print_board();
//    board1.print_board();


    board1.try_capture(21, 12);
    board1.print_board();
//
//    board1.try_capture(0, 9);
////    board1.print_board();
//
//    board1.try_capture(5, 12);
//
//
//    board1.try_capture(29, 24);
//
//
//    board1.try_capture(21, 14);



//    board1.squares_of_pieces[0]->generate_valid_moves();
//
//    board1.squares_of_pieces[0]->print_valid_moves();

//    board1.move_piece(8,12);


//    int p[2];
//    int j;
//
//    for (j=0; j<32; j++) {
//        cout << "Square %d :", j);
//        board1.squares_of_pieces[j]->return_valid_moves(p);
//        int i;
//        int size = sizeof p / sizeof *p;
////    cout << "Sizeof: %d  ", size);
//
//        for (i=0; i<size; i++) {
//            if (p[i] != '\0') {
//                cout << "%d  ", p[i]);
//            }
//
//        }
//        putchar('\n');
//    }


//    cout << "%d  ", p[0]);
//    cout << "%d  ", p[1]);


//
//    cout << "%d", p[i]);
//    for


//    int i;
//    for (i=0; i<34; i++) {
//        int empty = board1.check_space_empty(i);
//        cout << "%d", empty);
////        putchar('\n');
//    }

//    int dis = board1.calculate_distance(0, 4);
//    cout << "%d", dis);

    return 0;

}
