//cpp
#include "tic_tac_toe_data.h"

void TicTacToeData:: save_games(const vector<unique_ptr<TicTacToe>>& games)
{
    ofstream outfile;
    outfile.open("C:\Users\xavie\OneDrive\Documents\TicTacToeData.txt");
    for(auto& game : games)
    {
        auto pegs = game-> get_pegs();
        for(auto peg: pegs)
        {
            outfile << peg;
        }
        outfile << game->get_winner() << "\n";
    }
    outfile.close();
}


vector<unique_ptr<TicTacToe>> TicTacToeData :: get_games()
{
    vector<unique_ptr<TicTacToe>> games;
    ifstream infile;
    infile.open("C:\Users\xavie\OneDrive\Documents\TicTacToeData.txt");
    string line;
    if(infile.is_open())
    {
        
        while(getline(infile, line))
        {
            vector<string> pegs;
            for(size_t i = 0; i < (line.size() - 1); i++)
            {
                string ch(1, line[i]);
                pegs.push_back(ch);
            }
            string winner{line[line.size() - 1]};
            unique_ptr<TicTacToe> game;
            if (pegs.size() == 9)
            {
                game = make_unique<TicTacToe3>(pegs, winner);
            }
            else if (pegs.size() == 16)
            {
                game = make_unique<TicTacToe4>(pegs, winner);
            }
            games.push_back(move(game));
        }
        infile.close();
    }
    return games;
        
    
}




