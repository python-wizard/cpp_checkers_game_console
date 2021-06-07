#include "../include/game.h"

Game::Game() {


}

int Game::start_normal_game() {
    game_board = new Board;
    game_board->print_board();
}

int Game::check_game_ended() {

}


std::tuple<string, vector<int>, vector<int>, vector<int>, vector<int>> Game::load_from_file(string filename) { //string filename string,
//    string line;
//    string filename = "filename.txt";


    ifstream myfile(filename);
    if (!myfile.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
//        return EXIT_FAILURE;
    }

    vector<string> lines;
    string line;

    while (getline(myfile, line)) {
        lines.push_back(line);
    }


    myfile.close();

    string str_turn_color, str_black_pieces, str_white_pieces;
    vector<int> black_pieces, white_pieces;
    if (lines.size() >= 3) {
        str_turn_color = lines[0];
        str_black_pieces = lines[1];
        str_white_pieces = lines[2];

//        cout << str_turn_color << endl;
//        cout << str_black_pieces << endl;
//        cout << str_white_pieces << endl;

        stringstream ss_black(str_black_pieces);

        int hlp;
        while(ss_black >> hlp)
        {
            black_pieces.push_back(hlp);
        }

        stringstream ss_white(str_white_pieces);
        int hlp2;
        while(ss_white >> hlp2)
        {
            white_pieces.push_back(hlp2);
        }
#ifdef VERBOSE
        cout << "Black pieces";

        for(auto i: black_pieces)
            cout << i;

        cout << endl;



        cout << "White pieces";

        for(auto i: white_pieces)
            cout << i;

        cout << endl;
#endif
    }
    else {
        cout << "The file needs to have at least 3 lines. 1 - color; 2 - black pieces; 3 white pieces." << endl;
    }

    vector<int> black_kings, white_kings;
    string str_black_kings, str_white_kings;


    if (lines.size() >= 4) {

        str_black_kings = lines[4];

        stringstream ss_black(str_black_kings);
        int hlp;
        while(ss_black >> hlp)
        {
            black_kings.push_back(hlp);
        }
    }

    if (lines.size() >= 5) {

        str_white_kings = lines[5];

        stringstream ss_black(str_white_kings);
        int hlp;
        while(ss_black >> hlp)
        {
            white_kings.push_back(hlp);
        }
    }

//    return black_pieces;
    return std::make_tuple(str_turn_color, black_pieces, white_pieces, black_kings, white_kings); //str_turn_color,
}

int Game::load_game(string filename) {
    string str_color;
    vector<int> black_men, white_men, black_kings, white_kings;

    tuple<string, vector<int>, vector<int>, vector<int>, vector<int>> super_tuple;
    super_tuple = load_from_file(filename);


//
//    Board(vector <int> vector_black, vector <int> vector_white,
//            vector<int> vector_black_king = {}, vector<int> vector_white_king = {});

    tie(str_color, black_men, white_men, black_kings, white_kings) = super_tuple;

    if (str_color == "black") {
        turn = black;
    }
    else if (str_color == "white") {
        turn = white;
    }
    else {
        cout << "Something went wrong with the file format.;" << endl;
        cout << "There is no such color as " << str_color << "." << endl;
        return -1;
    }

    if (black_men.size() > 0 && black_men.size() < 31) {
#ifdef VERBOSE
        cout << "Both black_men and white_men vectors are of proper size" << endl;
#endif
    }
    else if (black_men.size() < 1) {
        if (black_kings.size() > 0 && black_kings.size() <31) {
#ifdef VERBOSE
            cout << "No black men but there is at least one black king" << endl;
#endif
        }
    }
    else {
        cout << "There are not enough black pieces or there are too many black pieces" << endl;
        return -1;
    }

    if (white_men.size() > 0 && white_men.size() < 31) {
#ifdef VERBOSE
        cout << "Both white_men and white_men vectors are of proper size" << endl;
#endif
    }
    else if (white_men.size() < 1) {
        if (white_kings.size() > 0 && white_kings.size() <31) {
#ifdef VERBOSE
            cout << "No white men but there is at least one white king" << endl;
#endif
        }
    }
    else {
        cout << "There are not enough white pieces or there are too many white pieces" << endl;
        return -1;
    }

    cout << "Loading game from: " << filename << " ." << endl;


    game_board = new Board(black_men, white_men, black_kings, white_kings);
    game_board->print_board();

}

int Game::save_game(string filename) { //string filename
    std::tuple<vector<int>, vector<int>> tuple_vectors_pieces;

    tuple_vectors_pieces = game_board->return_locations_pieces_board();

    vector<int> black_pieces, white_pieces;
    std::tie(black_pieces, white_pieces) = tuple_vectors_pieces;

    ofstream myfile;
    myfile.open (filename);

    string str_turn;
    if (turn == black) {
        str_turn = "black";
    }
    else if (turn == white) {
        str_turn = "white";
    }
    myfile << str_turn << endl;

    for (int &piece : black_pieces) {
        myfile << piece << ' ';
    }
    myfile << endl;

    for (int &piece : white_pieces) {
        myfile << piece << ' ';
    }
    myfile << endl;

//    myfile << "Writing this to a file.\n";
//    myfile << "Writing this to a file.\n";
    myfile.close();
    return 0;
}

void Game::print_logo() {

    string filename = "../logo2.txt";
    ifstream myfile(filename);
    if (!myfile.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
//        return EXIT_FAILURE;
    }

    string line;

    while (getline(myfile, line)) {
        cout << line << endl;
    }

    myfile.close();

}

void Game::print_menu_main_screen() {
    cout << "\n\n\n\n";
    cout << "Welcome to the wonderful game of Checkers. What do you want to do?" << endl;
    cout << "1. Play game of checkers from basic startup position. You'll need a partner. Black is first to move." << endl;
    cout << "2. Load game to from file to finish it with your friend" << endl;
    cout << "4. Exit the program." << endl;
}

int Game::control_panel() {
    int exit = 0;
    while (exit != 1) {
        ClearScreen();
        print_logo();
        print_menu_main_screen();
        int choice;

        cin >> choice;

        if (choice == 1) {
            start_normal_game();
            control_game(exit);
        }
        else if (choice == 2) {
            string filename;
            cout << "What is the name of the file that you want to save the game to :    ";
            cin >> filename;
            load_game(filename);
            control_game(exit);
        }
        if (choice == 4) {
            exit = 1;
            return 0;
        }
    }

}

    int Game::endgame_screen(int result) {
    ClearScreen();
    string str_win;

    game_board->print_board();
    cout << "Game ended" << "\n\n";
    if (result == -1) {
        str_win = "black";
    }
    else if (result == 1) {
        str_win = "white";
    }

    cout << "You can stay here and watch however long you want." << endl;
    cout << "Alternatively, you can put press \"100\" to save the game" << endl;
    cout << "Or \"200\" to exit to the main screen." << endl;
    cout << "Or \"400\" to exit the program." << endl;

    cout << "The game was won by "<< str_win << " . Congratulations!!!\n\n" << endl;
    int choice;
    while (1) {
        cin >> choice;

        if (choice == 100) {
            string filename;
            cout << "What is the name of the file that you want to save the game to :    ";
            cin >> filename;
            save_game(filename);
            break;
        }

        if (choice == 200) {
            return 0;
        }

        if (choice == 400) {
            exit(0);
        }


    }




}

    int Game::control_game(int &exit) {
//        system ("cls");
//        std::system("cls");
        int move = 0;
        int endgame = 0;
        ClearScreen();
        game_board->print_board();
        string str_color;
        if (turn == black)
            str_color = "black";

        else
            str_color = "white";


        cout << "It's " << str_color << "'s move. If you want to move first provide square number of the square where \n";
        cout << "you're moving from and then provide the number of the square where you're moving to ." << endl;
        cout << "Alternatively you can put press \"100\" to save the game" << endl;
        cout << "Or \"200\" to exit to the main screen." << endl;
        cout << "Or \"400\" to exit the program." << endl;


        int from, to;

        while (move != 1) {
            cout << "From:     ";
            cin >> from;

            if (from == 100) {
                string filename;
                cout << "What is the name of the file that you want to save the game to :    ";
                cin >> filename;
                save_game(filename);
                break;
                return 0;
            }

            if (from == 200) {
                return 0;
            }

            if (from == 400) {
                exit = 1;
                return 0;
            }

            cout << "To:       ";
            cin >> to;

            if (from >= 0 && from < 32 && to >= 0 && to < 32) {
                move = make_move(from, to);
                if (move == 1) {
                    endgame = game_board->check_player_has_no_pieces();
                    if (endgame != 0) {
                        endgame_screen(endgame);
                    }
                    control_game(exit);
                }
            }
            else {
                cout << "The squares are numbered from 0 to 31. Number out of range" << endl;
            }


        }

}

int Game::make_move(int from, int to) {

    int move = game_board->whole_move_procedure(from, to, turn);
    if (move == 1) {
        if (turn == black) {
            turn = white;
        }
        else if (turn == white) {
            turn = black;
        }
    }
    return move;
}





//int Game::save_game() { //string filename
//
//    std::vector<int> v{0,1,2,4,8,16,32,64,128,256,512};
//    std::ofstream outfile("test.data");
//
//    std::for_each(v.begin(), v.end(), [&outfile](int x){outfile << x << " ";});
//
//}

//int Game::load_game() { //string filename
//    vector<int> datavec;
//    ifstream infile;
//
//    infile.open ("test.data", ios::in | ios::binary);
//
//    while (infile) {
//        int val;
//        infile.read(reinterpret_cast<char *>(&val), sizeof(int));
//        if (infile.bad()) {
//            throw std::runtime_error("Failed to read from infile!");
//        }
//        if (infile.eof()) break;
//        datavec.push_back(val);
//    }
//
//    cout << "Read data file. Contents of datavec: \n";
//    for (auto val : datavec) {
//        cout << val << ", ";
//    }
//    cout << "\nDone\n";
//}