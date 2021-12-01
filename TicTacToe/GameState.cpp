//
// GameState.cpp
//
// Created by Nelson Lee on 2021-10-01

#include "globals.h"
#include "GameState.h"
using namespace std;

//Constructor
GameState::GameState()
{
    selectedRow = 0;
    selectedColumn = 0;
    moveValid = true;
    gameOver = false;
    winCode = 0;
    turn = true;
    gameBoard[Empty][Empty];
}

// Return the Selected Row (in the range 0...boardSize-1)
int GameState::get_selectedRow()
{
    return selectedRow;
}

// Return the Selected Column (in the range 0..boardSize-1)
int GameState::get_selectedColumn()
{
    return selectedColumn;
}

// Set the Selected Row to Value in the range (in the range 0..boardSize-1)
void GameState::set_selectedRow(int value)
{
    this -> selectedRow = value;
}

// Set the Selected Column in the range (in the range 0..boardSize-1)
void GameState::set_selectedColumn(int value)
{
    this -> selectedColumn = value;
}

// Get the moveValid Value
bool GameState::get_moveValid()
{
    return moveValid;
}

// Set the moveValid Variable to Value
void GameState::set_moveValid(bool value)
{
    this -> moveValid = value;
}

// Get the gameOver Value
bool GameState::get_gameOver()
{
    return gameOver;
}

// Set the gameOver Variable to Value
void GameState::set_gameOver(bool value)
{
    this -> gameOver = value;
}

// Get the winCode [0..8]
int GameState::get_winCode()
{
    return winCode;
}

// Set the winCode to Value in the range (0..8)
void GameState::set_winCode(int value)
{
    this -> winCode = value;
}

// Get the Value of Turn
bool GameState::get_turn()
{
    return turn;
}

// Set the Value of Turn
void GameState::set_turn(bool value)
{
    this -> turn = value;
}

// Get the Game Board Value at the Board Location at row and col
// This method Checks that row, col and Value are in Range/Valid
// and if not it Returns Empty
int GameState::get_gameBoard(int row, int col) 
{
    if ( (row < 0) || (row > 2) || (col < 0) || (col > 2) ) 
    {
        return Empty;
    }
    else
    {
        return (gameBoard[row][col]);
    }
}

// Set the Game Board Value at the Board Location at row and col to Value
// This Method Checks that row, col and Value are in Range/Valid and if not it just Returns
void GameState::set_gameBoard(int row, int col, int value)
{
    if ( (row < 0) || (row > 2) || (col < 0) || (col > 2) ) 
    {
        return;
    }
    else
    {
        gameBoard[row][col]= value;
    }
}
