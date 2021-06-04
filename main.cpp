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
