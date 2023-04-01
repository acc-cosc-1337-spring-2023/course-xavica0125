//cpp
#include "tic_tac_toe.h"
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
    pegs={9, " "};
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

void TicTacToe::display_board() const
{
    for(int i = 0; i < pegs.size(); i++)
    {
        cout<<pegs[i]<<"|";
        if((i+1) % 3 == 0)
        {
            cout<<"\n";
        }
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
    bool win = false;
    int x_count = 0;
    int o_count = 0;
    for(int i = 0; i < 10; i+=4)
    {
        if(pegs[i] == "X")
        {
            x_count++;
        }

        else if(pegs[i] == "O")
        {
            o_count++;
        }
    }
    if(x_count == 3 || o_count == 3)
    {
        win = true;
    }
    else
    {
        x_count = 0;
        o_count = 0;
        for(int i = 2; i < 7; i+=2)
        {
            if(pegs[i] == "X")
            {
                x_count++;
            }

            else if(pegs[i] == "O")
            {
                o_count++;
            }
        }
        if(x_count == 3 || o_count == 3)
        {
            win = true;
        }
    }
    return win;
}

bool TicTacToe::check_row_win()
{
    bool win = false;
    if (pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X") 
    {
        win = true;
    } 
    else if (pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O") 
    {
        win = true;
    }

    if (pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X") 
    {
        win = true;
    } 
    else if (pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O") 
    {
        win = true;
    }

    if (pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X") 
    {
        win = true;
    } 
    else if (pegs[6] == "O" && pegs[7] == "O" && pegs[8] == "O") 
    {
        win = true;
    }

    return win;
}


bool TicTacToe::check_column_win()
{
    bool win = false;
    
    for(int i = 0; i < 3; i++)
    {
        int x_count = 0;
        int o_count = 0;
        for(int j = 0; j < 3; j++)
        {
            if(pegs[i+j*3] == "X")
            {
                x_count++;
            }

            else if(pegs[i+j*3] == "O")
            {
                o_count++;
            }
        }
        if(x_count == 3 || o_count == 3)
        {
            win = true;
        }
    }
    return win; 
}    

void main_menu()
{
    string continue_playing;
    do 
    {
        string choice;
        while(choice != "X" && choice != "O")
        {
            cout << "Please enter (X or O): ";
            cin >> choice;
        }
        if(choice == "X" || choice == "O")
        {
            TicTacToe game;
            game.start_game(choice);
            do
            {  
                int position;
                do
                {
                    cout <<"Please enter a position (1-9): ";
                    cin >> position;
                }while(position < 1 && position > 9);
                game.mark_board(position);
                game.display_board();
            }while (!game.game_over());
            cout<<"Winner is "<<game.get_winner()<<"!!!\n";
            cout << "Do you want to continue playing? (Y/N): ";
            cin >> continue_playing;
        }
    }while(continue_playing == "Y" || continue_playing == "y");  
         
}