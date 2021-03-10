# TicTacToe
This is a C++ Tic Tac Toe game I am working on where the user plays against a perfect opponent. This entire project went from an idea to the completed 1.0.0 version in under 24 hours. 

## Description
This program has two modes: A two-player mode and a single-player mode against a perfect AI opponent. In order to play perfectly, the AI opponent implements the algorithm found at the following wikipedia page https://en.wikipedia.org/wiki/Tic-tac-toe#Strategy.

## Getting Started
Download the files and run the makefile provided. Make sure you have C++11 or later installed on your computer.

## Usage
All inputs to the program will simply loop until a valid input is entered, there are no error messages. The game will also not allow you to play invalid moves.
In order to make a move, simply write the row and column numbers given in the asci gui for the square you want to move into.
Below is an example screenshot of moving into the top left square on the first move of the game:
![image](https://user-images.githubusercontent.com/17460504/110564847-86c3a180-811b-11eb-830e-ffa9fcf99e0f.png)

The game will halt when when either a player has won or it is determined that the game is a draw. 
