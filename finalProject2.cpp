//-------------------------------------------------------------------------
// Program file   : finalproject2.cpp
// Course         : ITT200
// Inst.          : University of the Commonwealth Caribbean
// Purpose        : Traverse and provide best solution to a maze
// Date Created   : July 1, 2021
// Student ID No. : 20204241
// Author         : Camarly Thomas
// DISCLAIMER     : I CERTIFY THATI HAVE NOT GIVEN OR RECEIVED ANY UNAUTHORIZED ASSISTANCE ON THIS ASSIGNMENT@
//-------------------------------------------------------------------------


#include <iostream>
#include "maze.h"
#include <stack>
#include <vector>
#include <string>


#define ROWS 15
#define COLS 22

using namespace std;

stack<string> moves;
stack<int> maze_row;
stack<int> maze_column;


int main() {

	maze game;

    int maze[ROWS][COLS] = {
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 2, 1, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 1},
                     {1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
                     {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
                     {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                     {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                     {1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                     {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                     {1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 2, 1},
                     {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1},
                     {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                     {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                     {1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                   };

    int solution[ROWS][COLS] = {
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                   };




    string maze2[ROWS][COLS] = {
            {"1",  "1",  "1", "1", "1", "1", "1", "1", "1",  "1", "1", "1", "1",  "1", "1", "1",  "1", "1", "1", "1", "1",  "1"},
            {"1",  "R1", "1", "0", "0", "0", "0", "1", "R3", "1", "0", "0", "0",  "0", "1", "R5", "1", "0", "0", "0", "0",  "1"},
            {"1",  "0",  "1", "0", "0", "0", "0", "1", "0",  "1", "0", "0", "0",  "0", "1", "0",  "1", "0", "0", "0", "0",  "1"},
            {"1",  "0",  "1", "1", "1", "1", "1", "1", "0",  "1", "1", "1", "1",  "0", "1", "0",  "1", "0", "1", "1", "1",  "1"},
            {"1",  "0",  "0", "0", "0", "0", "0", "0", "0",  "0", "0", "0", "0",  "0", "0", "0",  "0", "0", "0", "0", "R7", "1"},
            {"1",  "1",  "1", "1", "1", "0", "1", "1", "1",  "1", "0", "1", "0",  "0", "0", "0",  "0", "0", "1", "1", "1",  "1"},
            {"1",  "0",  "0", "0", "0", "0", "1", "0", "0",  "0", "0", "1", "0",  "0", "0", "0",  "0", "0", "0", "0", "0",  "1"},
            {"1",  "1",  "1", "1", "1", "0", "1", "0", "1",  "0", "0", "1", "0",  "1", "1", "1",  "1", "1", "1", "1", "0",  "1"},
            {"E2", "0",  "0", "0", "0", "0", "1", "0", "1",  "0", "0", "1", "0",  "0", "0", "0",  "0", "0", "0", "1", "0",  "1"},
            {"1",  "1",  "1", "1", "1", "0", "1", "0", "1",  "0", "0", "1", "0",  "1", "0", "0",  "0", "0", "0", "1", "R6", "1"},
            {"1",  "0",  "0", "0", "1", "0", "1", "0", "1",  "0", "0", "1", "0",  "1", "0", "0",  "0", "0", "0", "1", "1",  "1"},
            {"1",  "0",  "0", "0", "0", "0", "1", "0", "1",  "0", "0", "1", "0",  "1", "0", "0",  "0", "0", "0", "0", "0",  "1"},
            {"1",  "1",  "1", "1", "1", "1", "1", "0", "1",  "0", "0", "1", "0",  "1", "0", "0",  "0", "0", "0", "0", "0",  "1"},
            {"1",  "R8", "0", "0", "0", "0", "0", "0", "1",  "0", "0", "1", "0",  "1", "0", "0",  "0", "0", "0", "0", "0",  "1"},
            {"1",  "1",  "1", "1", "1", "1", "1", "1", "1",  "1", "1", "1", "E4", "1", "1", "1",  "1", "1", "1", "1", "1",  "1"}};

    cout << "\t\t\tTraversal® " << endl;
    cout << "\n\t\t\t©SKY Games\n" << endl;

    char choice;;

    game.menuItems();

    cin >> choice;



    switch (choice) {
        case '1':
            game.traversal(maze, moves);
            break;

        case '2':
            game.printMaze(solution, maze, moves);
        	//traversalv2(solution, maze, maze_row, maze_column);
            break;

        case '@':
            game.aboutMe();
            break;

        case '3':
            game.helpService();
            break;

        default:
        	cout << "since you are trying to be smart, how about we play the maze game?";
            game.traversal(maze, moves);
            break;
    }

    game.thankYou();


	return 0;
}