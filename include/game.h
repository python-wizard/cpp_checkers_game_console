#ifndef CHECKERS_CONSOLE_GAME_H
#define CHECKERS_CONSOLE_GAME_H
#include "other.h"
#include "../include/board.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

class Game {
    Color turn = black;
    int game_ended = 0;
    Color winner;
    Board *game_board;

    void print_logo();
    void print_menu_main_screen();
    int control_game();
    int make_move(int from, int to);
    int endgame_screen(int results);
    int start_normal_game();
//    int check_game_ended();
    std::tuple<string, vector<int>, vector<int>, vector<int>, vector<int>> load_from_file(string filename); //str_turn_color,

public:

    Game();
    int control_panel();
    int load_game(string filename);
    int save_game(string filename);

    ~Game() = default;
};

#endif //CHECKERS_CONSOLE_GAME_H
