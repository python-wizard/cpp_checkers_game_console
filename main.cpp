#include <iostream>
#include <stdio.h>
#include <string.h>
#define VERBOSE
//using namespace std;
//#include <stdlib.h>

//#include "include/piece.h"
#include "include/board.h"
#include "include/game.h"


using namespace std;



int main() {

    Game game1;
    game1.save_game();
    game1.load_from_file();

    return 0;

}
