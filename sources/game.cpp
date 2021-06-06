#include "../include/game.h"

Game::Game() {
    start_normal_game();

}

int Game::start_normal_game() {
    game_board = new Board;
    game_board->print_board();
}

int Game::check_game_ended() {

}


int Game::load_game() { //string filename
    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line, ' ') )
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else cout << "Unable to open file";
}

int Game::save_game() { //string filename
    std::tuple<vector<int>, vector<int>> tuple_vectors_pieces;

    tuple_vectors_pieces = game_board->return_locations_pieces_board();

    vector<int> black_pieces, white_pieces;
    std::tie(black_pieces, white_pieces) = tuple_vectors_pieces;

    ofstream myfile;
    myfile.open ("example.txt");

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