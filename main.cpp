#include <iostream>
using namespace std;

class Board {
    char squares[31];
    int size = 8;
public:
    void print_board();
};

void Board::print_board() {
    int i, j=0;
    for (i=0; i<32; i++) {
        if ((j%2) ==0) {
            printf("   ");
        }
        printf("%3d", i);
        if ((j%2) == 1) {
            printf("   ");
        }
        if ((i%4) == 3) {
            j++;
            putchar('\n');
        }
    }
}

int main() {
//    std::cout << "Hello, World!" << std::endl;

    Board board1;
    board1.print_board();

    return 0;

}
