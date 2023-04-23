#include "tic_tac_toe_3.h"

bool TicTacToe3:: check_column_win()
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

bool TicTacToe3:: check_diagonal_win()
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

bool TicTacToe3:: check_row_win()
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

