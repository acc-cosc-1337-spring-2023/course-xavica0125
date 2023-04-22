//cpp
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"
bool TicTacToe::check_board_full()
{
    bool full = true;
    for(auto p : pegs)
    {
        if(p == " ")
        {
            full = false;
            break;
        }
    }
    return full;
}

void TicTacToe::clear_board()
{
    pegs.resize(9);
    std::fill(pegs.begin(),pegs.end()," ");
}

void TicTacToe::set_next_player()
{
    if(player == "X")
    {
        player = "O";
    }
    else if (player == "O")
    {
        player = "X";
    }
    
}

string TicTacToe:: get_player() const
{
    return player;
}

void TicTacToe::mark_board(int position)
{   
    if(pegs[position-1] == " ")
    {
        pegs[position-1] = get_player();
        set_next_player();
    }
    

}

void TicTacToe::start_game(string choice)
{
    clear_board();
    if(choice == "X" || choice == "O")
    {
        player = choice;
        
    }
    
}

bool TicTacToe::game_over()
{
    bool won = false;
    if(check_column_win() || check_diagonal_win() || check_row_win())
    {
        set_winner();
        won = true;
        
    }
    else if(check_board_full())
    {
        winner = "C";
        won = true;
    }
    return won;
}

string TicTacToe::get_winner()
{
    return winner;
}

void TicTacToe::set_winner()
{
    if(player == "X")
    {
        winner = "O";
    }
    else if(player == "O")
    {
        winner = "X";
    }
}

bool TicTacToe::check_diagonal_win()
{
    return false;
}

bool TicTacToe::check_row_win()
{
    return false;
}


bool TicTacToe::check_column_win()
{
    return false; 
}    

std::istream& operator>>(std::istream& num, TicTacToe& game)
{
    int position;
    if(game.pegs.size() == 9)
    {   
        
        cout << "Please enter a position (1-9): ";
        num >> position;
        game.mark_board(position);
    }
    else if(game.pegs.size() == 16)
    {
        cout << "Please enter a position (1-16): ";
        num >> position;
        game.mark_board(position);
    }
    return num;
}

std::ostream& operator<<(std::ostream& out,const TicTacToe& game)
{
    if(game.pegs.size() == 9)
    {
        out<< game.pegs[0] << "|" << game.pegs[1] << "|"<< game.pegs[2]<<"\n";
        out<< game.pegs[3] << "|" << game.pegs[4] << "|"<< game.pegs[5]<<"\n";
        out<< game.pegs[6] << "|" << game.pegs[7] << "|"<< game.pegs[8]<<"\n";
    }
    else if(game.pegs.size() == 16)
    {
        out<< game.pegs[0] << "|" << game.pegs[1] << "|"<< game.pegs[2]<< "|" << game.pegs[3] <<"\n";
        out<< game.pegs[4] << "|" << game.pegs[5] << "|"<< game.pegs[6]<< "|" << game.pegs[7] <<"\n";
        out<< game.pegs[8] << "|" << game.pegs[9] << "|"<< game.pegs[10]<< "|" << game.pegs[11] <<"\n";
        out<< game.pegs[12] << "|" << game.pegs[13] << "|"<< game.pegs[14]<< "|" << game.pegs[15] <<"\n";
    }
    
    return out;
}




void main_menu()
{
    string continue_playing;
    string choice;
    string game_type;
    unique_ptr <TicTacToe> game;
    TicTacToeData data_inst;
    TicTacToeManager manager(data_inst);
	do
	{
  		cout << "Please enter (X or O): ";
    	cin >> choice;      
    	if(choice == "X" || choice == "O")
    	{
            
            cout<<"Play TicTacToe3 (3) or TicTacToe4 (4)? : ";
            cin>>game_type;
            
            if(game_type == "3")
            {
                game = make_unique<TicTacToe3>();
            }
        	else if (game_type == "4")
            {
                game = make_unique<TicTacToe4>();
            }
            else
            {
                cout<<"Invalid choice. Please try again.\n";
                continue;
            }
        	game->start_game(choice);
			do
			{
				cin >> *game;
				cout << *game <<"\n";
				
			} while (!game->game_over());
			manager.save_game(game);
		}
		scoreboard(manager);
        cout << "Do you want to continue playing? (Y/N): ";
        cin >> continue_playing;
    		
	}while(continue_playing != "N" && continue_playing != "n");
	
	
	cout << manager << "\n";
    scoreboard(manager);
}

void scoreboard(TicTacToeManager& manager)
{
    int o_wins,x_wins,ties;
		manager.get_winner_total(o_wins,x_wins,ties);
		cout << "O Wins: " << o_wins <<"\n";
		cout << "X Wins: " << x_wins <<"\n";
		cout << "Ties: " << ties <<"\n";
}