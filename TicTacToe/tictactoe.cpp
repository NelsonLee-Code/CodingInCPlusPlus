//
//  TicTacToe.cpp
//
//  Created by Nelson Lee on 2021-10-01

#include <iostream>
#include <string>
using namespace std;

#include "globals.h"
#include "GameState.h"

// Function Prototype for PlayMove
void playMove(GameState&);

// The main function
int main() {

    /**********************************************************************************/
    /* Create an Initialized Game State Object                                        */
    /**********************************************************************************/
    GameState game_state;
    
    //Set Board to 0
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            game_state.set_gameBoard(i, j, 0);
        }
    }
    
    game_state.set_turn(true);
  
    // Read Two Integers from the User that Represent Row and Column    

    int row;
    int col;
  
    while (!game_state.get_gameOver()) 
    {
        cout << "Enter row and column of a grid cell: ";
        cin >> row >> col;
        
        // Check that the read row and column values are valid grid coordinates
        if ( (row < 0) || (row > 2) || (col < 0) || (col > 2) ) 
        {
            cout << "Invalid board coordinates " << row << " " << col << endl << endl;
            continue;
        }
        
        cout << "Selected row " << row << " and column " << col << endl; 
        game_state.set_selectedRow(row);
        game_state.set_selectedColumn(col);
        
        // Call PlayMove
        playMove(game_state);
        cout << "Game state after playMove:" << endl;
        
        cout << "Board: " << endl;

        //Declare Holding Array
        char *holdingArray[3][3]= {{"", "", ""}, {"", "", ""}, {"", "", ""}};
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (game_state.get_gameBoard(i, j) == 0)
                {
                    holdingArray[i][j] = "B";
                }
                else if (game_state.get_gameBoard(i, j) == 1)
                {
                    holdingArray[i][j] = "X";
                }
                else if (game_state.get_gameBoard(i, j) == 2)
                {
                    holdingArray[i][j] = "O";
                }
            }
        }
        
        cout << "   " << holdingArray[0][0] << " " << holdingArray[0][1] << " " << holdingArray[0][2] << endl;
        cout << "   " << holdingArray[1][0] << " " << holdingArray[1][1] << " " << holdingArray[1][2] << endl;
        cout << "   " << holdingArray[2][0] << " " << holdingArray[2][1] << " " << holdingArray[2][2] << endl;
        
        std::cout << std::boolalpha;   
        cout << "moveValid: " << game_state.get_moveValid() << endl;
        cout << "gameOver: " << game_state.get_gameOver() << endl;
        cout << "winCode: " << game_state.get_winCode() << endl;
        cout << endl;
    }
    
    return 0;
}
