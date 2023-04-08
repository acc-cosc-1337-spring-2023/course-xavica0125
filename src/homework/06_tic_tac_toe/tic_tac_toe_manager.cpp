//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager:: save_game(TicTacToe game)
{
    games.push_back(game);
    update_winner_count(game.get_winner());
}

std::ostream& operator<<(std::ostream& out,const TicTacToeManager & manager)
{
    
    for(const auto& game : manager.games)
    {
        out << game << "\n";
    }
    return out;
}

void TicTacToeManager:: get_winner_total(int& o, int& w, int& t)
{
    o = o_win;
    w = x_win;
    t = ties;
}

void TicTacToeManager:: update_winner_count(string winner)
{
    if (winner == "X")
    {
        x_win++;
    }
    else if(winner == "O")
    {
        o_win++;
    }
    else
    {
        ties++;
    }
}