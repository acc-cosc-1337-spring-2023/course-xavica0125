//h
#include <iostream>
#include <vector>
#include <string>
using std::cout; using std::cin; using std::vector; using std::string;

class TicTacToe
{
    private:
        string player;
        vector <string> pegs;
        void set_next_player();
        bool check_board_full();
        void clear_board();
    public:
        TicTacToe() : pegs(9," ") {}
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        void display_board() const;
        

};  

void main_menu();