//h
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using std::cout; using std::cin; using std::vector; using std::string; 
using std::unique_ptr; using std::make_unique;
#ifndef tic_tac_toe_h
#define tic_tac_toe_h
class TicTacToe
{
    private:
        string player;
        void set_next_player();
        bool check_board_full();
        void clear_board();
        void set_winner();
        string winner;
    protected:
        vector <string> pegs;
        virtual bool check_diagonal_win();
        virtual bool check_row_win();
        virtual bool check_column_win();
    public:
        TicTacToe(int size) : pegs(size*size," ") {}
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
