//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager:: save_game(unique_ptr<TicTacToe>& game)
{
    update_winner_count(game->get_winner());
    games.push_back(move(game)); 
}

std::ostream& operator<<(std::ostream& out,const TicTacToeManager& manager)
{
    
    for(const auto& game : manager.games)
    {
        out << *game << "\n";
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