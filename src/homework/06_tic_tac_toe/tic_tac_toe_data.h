//h
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <fstream>
#include <vector>
#include <string>
#include <memory>
using std::vector; using std::string; 
using std::unique_ptr; using std::make_unique; using std::move;
using std::ofstream; using std::ifstream;
#ifndef tic_tac_toe_data_h
#define tic_tac_toe_data_h

class TicTacToeData: public TicTacToe
{
    public:
        void save_games(const vector<unique_ptr<TicTacToe>>& games);
        vector<unique_ptr<TicTacToe>> get_games();
};

#endif 