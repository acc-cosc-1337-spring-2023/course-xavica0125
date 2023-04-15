#include "tic_tac_toe_4.h"

bool TicTacToe4:: check_column_win()
{
    bool win = false;
    
    for(int i = 0; i < 4; i++)
    {
        int x_count = 0;
        int o_count = 0;
        for(int j = 0; j < 4; j++)
        {
            if(pegs[i+j*4] == "X")
            {
                x_count++;
            }

            else if(pegs[i+j*4] == "O")
            {
                o_count++;
            }
        }
        if(x_count == 4 || o_count == 4)
        {
            win = true;
        }
    }
    return win;
}

bool TicTacToe4:: check_diagonal_win()
{
    bool win = false;
    int x_count = 0;
    int o_count = 0;
    for(int i = 0; i < 16; i+=5)
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
    if(x_count == 4 || o_count == 4)
    {
        win = true;
    }
    else
    {
        x_count = 0;
        o_count = 0;
        for(int i = 3; i <= 12; i+=3)
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
        if(x_count == 4 || o_count == 4)
        {
            win = true;
        }
    }
    return win;
}

bool TicTacToe4:: check_row_win()
{
    bool win = false;
    if (pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X" && pegs[3] == "X") 
    {
        win = true;
    } 
    else if (pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O" && pegs[3] == "O") 
    {
        win = true;
    }

    if (pegs[4] == "X" && pegs[5] == "X" && pegs[6] == "X" && pegs[7] == "X") 
    {
        win = true;
    } 
    else if (pegs[4] == "O" && pegs[5] == "O" && pegs[6] == "O" && pegs[7] == "X") 
    {
        win = true;
    }

    if (pegs[8] == "X" && pegs[9] == "X" && pegs[10] == "X" && pegs[11] == "X") 
    {
        win = true;
    } 
    else if (pegs[8] == "O" && pegs[9] == "O" && pegs[10] == "O" && pegs[11] == "O") 
    {
        win = true;
    }
    if (pegs[12] == "X" && pegs[13] == "X" && pegs[14] == "X" && pegs[15] == "X") 
    {
        win = true;
    } 
    else if (pegs[12] == "O" && pegs[13] == "O" && pegs[14] == "O" && pegs[15] == "O") 
    {
        win = true;
    }
    return win;
}
