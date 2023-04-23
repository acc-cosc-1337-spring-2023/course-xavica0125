//h
#include <iostream>
#include <vector>
#include <string>
#include "tic_tac_toe.h"
using std::cout; using std::cin; using std::vector; using std::string;
#ifndef tic_tac_toe_4_h
#define tic_tac_toe_4_h
class TicTacToe4: public TicTacToe
{
    public:
        TicTacToe4() : TicTacToe(4){}
        TicTacToe4(vector<string> p, string winner) : TicTacToe(p, winner){}
    private:
        bool check_column_win() ;
        bool check_row_win() ;
        bool check_diagonal_win() ;
};

#endif