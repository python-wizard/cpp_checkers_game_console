#ifndef CHECKERS_CONSOLE_MAN_H
#define CHECKERS_CONSOLE_MAN_H

#include "piece.h"

class Man: public Piece {

public:


    char return_descriptive_char();



    vector <int> generate_possible_moves();
    vector<std::tuple<int, int>> generate_possible_captures();


    // konstruktory
    Man(Color color_, int location_);
    ~Man();
};

#endif //CHECKERS_CONSOLE_MAN_H
