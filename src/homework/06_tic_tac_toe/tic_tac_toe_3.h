//h
#include <iostream>
#include <vector>
#include <string>
#include "tic_tac_toe.h"
using std::cout; using std::cin; using std::vector; using std::string;
#ifndef tic_tac_toe_3_h
#define tic_tac_toe_3_h
class TicTacToe3: public TicTacToe
{
    public:
        TicTacToe3() : TicTacToe(3){}
    private:
        bool check_column_win() ;
        bool check_row_win() ;
        bool check_diagonal_win() ;
};
#endif