#ifndef CHECKERS_CONSOLE_KING_H
#define CHECKERS_CONSOLE_KING_H

#include "piece.h"


class King: public Piece {



public:

    char return_descriptive_char();
    vector <int> generate_possible_moves();
    vector<std::tuple<int, int>> generate_possible_captures();

    // konstruktory
    King(Color color_, int location_);
    ~King();


};

#endif //CHECKERS_CONSOLE_KING_H
