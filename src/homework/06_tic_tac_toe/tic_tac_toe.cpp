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
    return check_board_full();
}

void main_menu()
{
    string continue_playing;
    do 
    {
        
        string choice;
        cout << "Please enter (X or O): ";
        cin >> choice;
        TicTacToe game;
        game.start_game(choice);

    
        do
        {  
            int position;
            cout <<"Please enter a position (1-9): ";
            cin >> position;
            game.mark_board(position);
            game.display_board();
        }while (!game.game_over());
        
        cout << "Do you want to continue playing? (Y/N): ";
        cin >> continue_playing;
    }while(continue_playing == "Y" || continue_playing == "y"); 
}