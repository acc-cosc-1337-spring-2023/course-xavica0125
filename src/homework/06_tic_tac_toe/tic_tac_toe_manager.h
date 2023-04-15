//h
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
using std::cout; using std::cin; using std::vector; using std::string; using std::unique_ptr;
#ifndef tic_tac_toe_manager_h
#define tic_tac_toe_manager_h

class TicTacToeManager
{
    private:
        vector <unique_ptr<TicTacToe>> games;
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        void update_winner_count(string winner);
    public:
        void save_game(unique_ptr<TicTacToe>& game);
        friend std::ostream& operator<<(std::ostream & out,const TicTacToeManager & manager);
        void get_winner_total(int& o, int& w, int& t);
};
#endif

void scoreboard(TicTacToeManager&);
  