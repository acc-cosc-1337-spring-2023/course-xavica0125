//h
#include <iostream>
#include <vector>
#include <string>
using std::cout; using std::cin; using std::vector; using std::string;
#ifndef tic_tac_toe_h
#define tic_tac_toe_h
class TicTacToe
{
    private:
        string player;
        vector <string> pegs;
        void set_next_player();
        bool check_board_full();
        void clear_board();
        void set_winner();
        bool check_diagonal_win();
        bool check_row_win();
        bool check_column_win();
        string winner;
    public:
        TicTacToe() : pegs(9," ") {}
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        string get_winner();
        friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
        friend std::istream& operator>>(std::istream& num, TicTacToe& game);
};  

#endif

void main_menu();
