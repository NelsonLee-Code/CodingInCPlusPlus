//
//  playMove.cpp
//  

#include "globals.h"
#include "GameState.h"

void playMove(GameState& game_state) 
{
    //Initialize Basic Variables
    int row, col, tileValue;
    bool turn;

    //Set Variables Based On Targets
    row = game_state.get_selectedRow();
    col = game_state.get_selectedColumn();
    turn = game_state.get_turn();

    //See if Inputted Tile is AVAILABLE
    tileValue = game_state.get_gameBoard(row, col);

    //Exit playMove.cpp if INVALID MOVE!
    if (tileValue != Empty) 
    {
        game_state.set_moveValid(false);
        game_state.set_gameOver(false);
        game_state.set_winCode(0);
    } 
    else 
    {
        game_state.set_moveValid(true);

        int inputValue;

        //Initialize What Value to Input
        if (game_state.get_turn() == true) 
        {
            game_state.set_gameBoard(row, col, 1);
            inputValue = 1;
        }
        if (game_state.get_turn() == false) 
        {
            game_state.set_gameBoard(row, col, 2);
            inputValue = 2;
        }

        //Check if WinCode = 8 
        if (game_state.get_gameBoard(2, 0) == inputValue && game_state.get_gameBoard(1, 1) == inputValue && game_state.get_gameBoard(0, 2) == inputValue) 
        {
            game_state.set_winCode(8);
            game_state.set_gameOver(true);
        }
        //Check if WinCode = 7
        else if (game_state.get_gameBoard(0, 0) == inputValue && game_state.get_gameBoard(1, 1) == inputValue && game_state.get_gameBoard(2, 2) == inputValue) 
        {
            game_state.set_winCode(7);
            game_state.set_gameOver(true);
        }//Check if WinCode = 6
        else if (game_state.get_gameBoard(0, 2) == inputValue && game_state.get_gameBoard(1, 2) == inputValue && game_state.get_gameBoard(2, 2) == inputValue) 
        {
            game_state.set_winCode(6);
            game_state.set_gameOver(true);
        }//Check if WinCode = 5
        else if (game_state.get_gameBoard(0, 1) == inputValue && game_state.get_gameBoard(1, 1) == inputValue && game_state.get_gameBoard(2, 1) == inputValue) 
        {
            game_state.set_winCode(5);
            game_state.set_gameOver(true);
        }//Check if WinCode = 4
        else if (game_state.get_gameBoard(0, 0) == inputValue && game_state.get_gameBoard(1, 0) == inputValue && game_state.get_gameBoard(2, 0) == inputValue) 
        {
            game_state.set_winCode(4);
            game_state.set_gameOver(true);
        }//Check if WinCode = 3
        else if (game_state.get_gameBoard(2, 0) == inputValue && game_state.get_gameBoard(2, 1) == inputValue && game_state.get_gameBoard(2, 2) == inputValue) 
        {
            game_state.set_winCode(3);
            game_state.set_gameOver(true);
        }//Check if WinCode = 2
        else if (game_state.get_gameBoard(1, 0) == inputValue && game_state.get_gameBoard(1, 1) == inputValue && game_state.get_gameBoard(1, 2) == inputValue) 
        {
            game_state.set_winCode(2);
            game_state.set_gameOver(true);
        }
        //Check if WinCode = 1
        else if (game_state.get_gameBoard(0, 0) == inputValue && game_state.get_gameBoard(0, 1) == inputValue && game_state.get_gameBoard(0, 2) == inputValue) 
        {
            game_state.set_winCode(1);
            game_state.set_gameOver(true);
        } 
        else if (game_state.get_gameBoard(0, 0) != 0 && game_state.get_gameBoard(0, 1) != 0 && game_state.get_gameBoard(0, 2) != 0 && game_state.get_gameBoard(1, 0) != 0 && game_state.get_gameBoard(1, 1) != 0 && game_state.get_gameBoard(1, 2) != 0 && game_state.get_gameBoard(2, 0) != 0 && game_state.get_gameBoard(2, 1) != 0 && game_state.get_gameBoard(2, 2) != 0) 
        {
            game_state.set_winCode(0);
            game_state.set_gameOver(true);
        } //No One Wins
        else 
        {
            game_state.set_winCode(0);
            game_state.set_gameOver(false);
        }

        //Change Turn
        if (game_state.get_turn() == true) 
        {
            game_state.set_turn(false);
        } 
        else 
        {
            game_state.set_turn(true);
        }
    }
}

