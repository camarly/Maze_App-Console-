//-------------------------------------------------------------------------
// Header Name   : maze.h
// Program file   : maze.h
// Course         : ITT200
// Inst.          : University of the Commonwealth Caribbean
// Purpose        : Traverse and provide best solution to a maze
// Date Created   : July 1, 2021
// Student ID No. : 20204241
// Author         : Camarly Thomas
// DISCLAIMER     : I CERTIFY THATI HAVE NOT GIVEN OR RECEIVED ANY UNAUTHORIZED ASSISTANCE ON THIS ASSIGNMENT@
//-------------------------------------------------------------------------


/*
 * maze.h
 *
 *  Created on: 29 Jul 2021
 *      Author: cloud
 */

#ifndef MAZE_H_
#define MAZE_H_

#include <iostream>
#include <stack>
#include <vector>
#include <string>


#define ROWS 15
#define COLS 22


const int VISITED = 2;
const int WALL = 1;

//stack<string> moves;
//stack<int> maze_row;
//stack<int> maze_column;

using namespace std;

class maze{
private:
	string insideMaze[ROWS][COLS];
	int insideMaze2[ROWS][COLS];
	int solution[ROWS][COLS];

public:
	maze();
	bool deadEnd(int maze[ROWS][COLS], int current_row, int current_col);
	bool isDestination(int pos_row, int pos_col, int destination_row, int destination_col);
	bool validMove(int maze[ROWS][COLS], int solution[ROWS][COLS], int i, int j, string direction);
	void printMaze(int solution[ROWS][COLS], int maze[ROWS][COLS], stack<string> moves);
	void traversal(int maze[ROWS][COLS], stack<string> moves);
	void traversalv2(int solution[ROWS][COLS], int maze[ROWS][COLS], stack<int> maze_row, stack<int> maze_col);
	void helpService();
	void mazeSolution();
	void menuItems();
	void mazeLoser();
	void mazeWalker();
	void wallDisplay();
	void thankYou();
	void aboutMe();
	void getMaze();
	void movesList();

};


maze::maze(){
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


}



//-------------------------------------------------------------------------
// Function Name : mazeLoser
// Purpose       : display walking lost person who has reached an obstacle
//-------------------------------------------------------------------------
void maze::mazeLoser(){
    cout <<  "  2 " << endl;
    cout <<  "  ≤))≥ " << endl;
    cout <<  "__| \\__ " << endl;
    cout << endl;
}



//-------------------------------------------------------------------------
// Function Name : mazeLoser
// Purpose       : display walking lost person who has reached an obstacle
//-------------------------------------------------------------------------
void maze::wallDisplay(){
    cout << "________________________________________________________\n";
    cout << "|___|___|___|___|___|___|___|___|___|___|___|___|___|___\n";
    cout << "__|___|___|___|___|___|___|___|___|___|___|___|___|___|__\n";
    cout << "|___|___|___|___|___|___|___|___|___|___|___|___|___|___\n";
    cout << "__|___|___|___|___|___|___|___|___|___|___|___|___|___|__\n";
    cout << "|___|___|___|___|___|___|___|___|___|___|___|___|___|___\n";
    cout << endl;
}



//-------------------------------------------------------------------------
// Function Name : mazeWalker
// Purpose       : display walking lost person still on okay path
//-------------------------------------------------------------------------
void maze::mazeWalker(){
    printf ( "   /2 " );
    cout <<  "   /(`)\\ " << endl;
    cout <<   " __/ \\__ " << endl;
    cout << endl;
}


//-------------------------------------------------------------------------
// Function Name : helpService
// Purpose       : prints the solution directions for each room
//-------------------------------------------------------------------------
void maze::helpService(){
    cout << "You were helped" << endl;
}



//-------------------------------------------------------------------------
// Function Name : deadEnd
// Purpose       : checks if movement is blocked by wall
//-------------------------------------------------------------------------
bool maze::deadEnd(int maze[ROWS][COLS], int current_row, int current_col){
    if((current_row+1<ROWS-1 && maze[current_row+1][current_col] != 0) && (current_row-1>=0 && maze[current_row-1][current_col] != 0) && (current_col+1<COLS-1 && maze[current_row][current_col+1] != 0) && (current_col-1>=0 && maze[current_row][current_col-1] != 0)){
        return true;
    }
    return false;
}



bool maze::validMove(int maze[ROWS][COLS], int solution[ROWS][COLS], int i, int j, string direction){
	if(direction == "L"){
		j= j-1;
	}
	else if(direction == "R"){
		j= j+1;
	}
	else if(direction == "U"){
		i = i-1;
	}
	else if(direction == "D"){
		i= i +1;
	}

	if(maze[i][j] == 0){
		return true;
	}
	else{
		return false;
	}
	return false;
}





//-------------------------------------------------------------------------
// Function Name : bestPath/printMaze
// Purpose       : prints the solution directions for each room
//-------------------------------------------------------------------------
void maze::printMaze(int solution[ROWS][COLS], int maze[ROWS][COLS], stack<string> moves){

    int start_room;

    int exits[2][2]={{8,0},{14,12}}; // possible destinations

    int room1[2] = {1, 1};
    int room2[2] = {1, 8};
    int room3[2] = {1, 15};
    int room4[2] = {4, 20};
    int room5[2] = {9, 20};
    int room6[2] = {13, 1};

    int current_col, next_col = 0;
    int current_row, next_row = 0;


    do{
    cout << "Choose your starting room. [1-6] ";
    cin >> start_room;
    }while(start_room < 1 || start_room > 6);

    //setting start points as visited.
    switch (start_room) {
        case 1:
           // room1;
            current_row = room1[0];
            current_col = room1[1];
            break;
        case 2:
           // room2;
            current_row = room2[0];
            current_col = room2[1];
            break;
        case 3:
           // room3;
            current_row = room3[0];
            current_col = room3[1];
            break;
        case 4:
           // room4;
            current_row = room4[0];
            current_col = room4[1];
            break;
        case 5:
           // room5;
            current_row = room5[0];
            current_col = room5[1];
            break;
        case 6:
           // room6;
            current_row = room6[0];
            current_col = room6[1];
            break;
        default:
           // room1;
            current_row = room1[0];
            current_col = room1[1];
            break;
    }


    cout << "The solution from room " << start_room << " is: \n" << endl;

	for(int row=0; row<ROWS; row++) {
		for(int col=0; col<COLS; col++) {
			//solution[current_row][current_col] = VISITED;
			//solution[row][col] = 2;


			if(maze[current_row][current_col+1] == 0){
				solution[current_row][current_col+1] = 5;
				current_col++;
				moves.push("R");

			}
			else if(maze[current_row][current_col-1] == 0){
				solution[current_row][current_col-1] = 5;
				current_col--;
				moves.push("L");

			}
			else if(maze[current_row+1][current_col] == 0){
				solution[current_row+1][current_col] = 5;
				current_row++;
				moves.push("D");
			}
			else if(maze[current_row-1][current_col] == 0){
				solution[current_row-1][current_col] = 5;
				current_row--;
				moves.push("U");
			}
			else if(maze[current_row][current_col+1] == 1){
					current_col--;
					if(maze[current_row+1][current_col] == 0){
					solution[current_row+1][current_col] = 5;
					current_row++;
					moves.push("D");
					}

			}
		}
	}


	for(int row=0; row<ROWS; row++) {
		for(int col=0; col<COLS; col++) {
			if(validMove(maze, solution, row, col, "D")){
				solution[row][col] = 5;
			}
			else{
				solution[row][col] = 1;
			}



			if(maze[current_row][current_col+1] == 0){
				solution[current_row][current_col+1] = 5;
				current_col++;
				moves.push("R");

			}
			else if(maze[current_row][current_col-1] == 0){
				solution[current_row][current_col-1] = 5;
				current_col--;
				moves.push("L");

			}
			else if(maze[current_row+1][current_col] == 0){
				solution[current_row+1][current_col] = 5;
				current_row++;
				moves.push("D");
			}
			else if(maze[current_row-1][current_col] == 0){
				solution[current_row-1][current_col] = 5;
				current_row--;
				moves.push("U");
			}
			else if(maze[current_row][current_col+1] == 1){
					current_col--;
					if(maze[current_row+1][current_col] == 0){
					solution[current_row+1][current_col] = 5;
					current_row++;
					moves.push("D");
					}

			}
		}
	}


    for(int i=0; i<ROWS; i++){
    	for(int j=0; j<COLS; j++){
    		cout << solution[i][j];
    	}
    	cout << endl;
    }

}



/*
//-------------------------------------------------------------------------
// Function Name : chk_move
// Purpose       :
//-------------------------------------------------------------------------
void chk_move(int maze[ROWS][COLS], int solution[ROWS][COLS], stack <string>moves, int i, int j, string direction){

	if(validMove(maze, solution, i, j, "L")){
		moves.push("L");
		chk_move(maze, solution, moves, i, j, "R");
		chk_move(maze, solution, moves, i, j, "U");
		chk_move(maze, solution, moves, i, j, "D");
	}
	moves.pop();

}
*/





//-------------------------------------------------------------------------
// Function Name : aboutMe
// Purpose       : displays information about the developers
//-------------------------------------------------------------------------
void maze::aboutMe(){
    cout << "SKY games is a child studio of Cloud Enterprises. Founder and CEO Camarly Thomas's second brainchild started in the late 2020s and is a AAA software and gaming studio based in Jamaica.\nNet Worth 1.5 Billion EUROS \n--STOCK MARKET DATA NOT AVAILABLE.\n" <<  endl;
}


//-------------------------------------------------------------------------
// Function Name : movesList
// Purpose       : display the movement controls
//-------------------------------------------------------------------------
void maze::movesList(){
    cout << "Your are in a maze, find a way out quickly!" << endl;
    cout << "\t\tMoves list\n\n" << endl;
    cout << "U - for Up" << endl;
    cout << "L - Left" << endl;
    cout << "R - Right" << endl;
    cout << "D - for Down" << endl;
}




//-------------------------------------------------------------------------
// Function Name : traversal
// Purpose       : navigates user through the maze to locate an exit
//-------------------------------------------------------------------------
void maze::traversal(int maze[ROWS][COLS], stack<string> moves){



   // int rooms[6][2]= {{1,1}, {1,8}, {1,15},{4, 20}, {9,20}, {13,1}}; // available starting points
    int exits[2][2]={{8,0},{14,12}}; // possible destinations

    int room1[2] = {1, 1};
    int room2[2] = {1, 8};
    int room3[2] = {1, 15};
    int room4[2] = {4, 20};
    int room5[2] = {9, 20};
    int room6[2] = {13, 1};


    string move;
    int start_room;

    int current_col, next_col = 0;
    int current_row, next_row = 0;

    do{
    cout << "Choose your starting room. [1-6] ";
    cin >> start_room;
    }while(start_room < 1 || start_room > 6);

    //setting start points as visited.
    switch (start_room) {
        case 1:
           // room1;
            current_row = room1[0];
            current_col = room1[1];
            break;
        case 2:
           // room2;
            current_row = room2[0];
            current_col = room2[1];
            break;
        case 3:
           // room3;
            current_row = room3[0];
            current_col = room3[1];
            break;
        case 4:
           // room4;
            current_row = room4[0];
            current_col = room4[1];
            break;
        case 5:
           // room5;
            current_row = room5[0];
            current_col = room5[1];
            break;
        case 6:
           // room6;
            current_row = room6[0];
            current_col = room6[1];
            break;
        default:
           // room1;
            current_row = room1[0];
            current_col = room1[1];
            break;
    }


   // current_row = start_room[0];
   // current_col = start_room[1];
    maze[current_row][current_col] = VISITED;


    movesList();
    cout << "\nCurrent Location: row " << current_row << ", col " << current_col << endl;


    do {
        cout << "Which way? ";
        cin >> move;

        if(move != "L" && move != "R" && move != "U" && move != "D") {
            cout << "Invalid move. Please try again." << endl;
            mazeLoser();
        }
        else {
            if(move == "L"){
                next_col = current_col - 1;
                next_row = current_row;
            }
            else if(move == "R"){
                next_col = current_col + 1;
                next_row = current_row;
            }
            else if(move == "U"){
                next_col = current_col;
                next_row = current_row - 1;
            }
            else if(move == "D"){
                next_col = current_col;
                next_row = current_row + 1;
            }
            if(maze[next_row][next_col] == VISITED) {
                cout << "Destination has already been visited" << endl;
            }
            else if(maze[next_row][next_col] == WALL) {
                cout << "Destination is a wall" << endl;
                wallDisplay();
            }
            else {
                moves.push(move);
                current_row = next_row;
                current_col = next_col;
                maze[current_row][current_col] = VISITED;
                cout << "current position is now row " << current_row << ", col " << current_col << endl;

                if(deadEnd(maze, current_row, current_col)) {
                    cout << "You are at a dead end!...going back to a valid move point" << endl;
                    mazeLoser();

                    do{
                        //reverse moves until a valid move is available
                        string temp = moves.top();
                        moves.pop();
                        if(temp == "L")
                            current_col++;
                        else if(temp == "R")
                            current_col--;
                        else if (temp == "U")
                            current_row++;
                        else
                            current_row--;
                    }while(deadEnd(maze, current_row, current_col));

                    cout << "current position is now row " << current_row << ", col " << current_col << endl;
                }
            }
        }
    }
    while((current_row != exits[0][0] || current_col != exits[0][1]) && (current_row != exits[1][0] || current_col != exits[1][1]));

    cout << "Congratulations, you have exited the maze!!!" << endl;

}




//-------------------------------------------------------------------------
// Function Name : traversalv2
// Purpose       : display maze solution from desired room
//-------------------------------------------------------------------------
void maze::traversalv2(int solution[ROWS][COLS], int maze[ROWS][COLS], stack<int> maze_row, stack<int> maze_col){



   // int rooms[6][2]= {{1,1}, {1,8}, {1,15},{4, 20}, {9,20}, {13,1}}; // available starting points
    int exits[2][2]={{8,0},{14,12}}; // possible destinations

    int room1[2] = {1, 1};
    int room2[2] = {1, 8};
    int room3[2] = {1, 15};
    int room4[2] = {4, 20};
    int room5[2] = {9, 20};
    int room6[2] = {13, 1};


    //string move;
    int start_room;

    int current_col, next_col = 0;
    int current_row, next_row = 0;

    do{
    cout << "Choose your starting room. [1-6] ";
    cin >> start_room;
    }while(start_room < 1 || start_room > 6);

    //setting start points as visited.
    switch (start_room) {
        case 1:
           // room1;
            current_row = room1[0];
            current_col = room1[1];
            break;
        case 2:
           // room2;
            current_row = room2[0];
            current_col = room2[1];
            break;
        case 3:
           // room3;
            current_row = room3[0];
            current_col = room3[1];
            break;
        case 4:
           // room4;
            current_row = room4[0];
            current_col = room4[1];
            break;
        case 5:
           // room5;
            current_row = room5[0];
            current_col = room5[1];
            break;
        case 6:
           // room6;
            current_row = room6[0];
            current_col = room6[1];
            break;
        default:
           // room1;
            current_row = room1[0];
            current_col = room1[1];
            break;
    }


   // current_row = start_room[0];
   // current_col = start_room[1];
    solution[current_row][current_col] = VISITED;


    //movesList();
    cout << "\nCurrent Location: row " << current_row << ", col " << current_col << endl;


	for(int i=0; i<15; i++){
		for(int j=0; j<22; j++){
			if((maze[current_row][current_col+1] == 0 && solution[current_row+1][current_col] == 0 && solution[current_row-1][current_col] == 0 && solution[current_row][current_col-1] == 0)){
				maze_col.push(current_col+1);
				cout << "column: " << current_col+1 << endl;
				current_col++;
			}
			else if(maze[current_row+1][current_col] == 0){
				maze_row.push(current_row+1);
				cout << "row: " << current_row+1<< endl;
				current_row++;
			}
			else if(maze[current_row][current_col-1] == 0){
				maze_col.push(current_col-1);
				cout << "column: " << current_col-1 << endl;
				current_col--;
			}
			else if(maze[current_row-1][current_col] == 0){
				maze_row.push(current_row-1);
				cout << "row: " << current_row-1  << endl;
				current_row--;

			}

		}
	}


}

//-------------------------------------------------------------------------
// Function Name : menuItems
// Purpose       : display the menu items
//-------------------------------------------------------------------------
void maze::menuItems(){
	cout << "\n\t\tCHOOSE YOUR PATH\n"<< endl;
    cout << "1 - Play Traversal" << endl;
    cout << "2 - Display solution" << endl;
    cout << "3 - Help" << endl;
    cout << "@ - About me\n" << endl;
    cout << "Make a selection: ";

}


//-------------------------------------------------------------------------
// Function Name : isDestination
// Purpose       : determine if position is located at destination
//-------------------------------------------------------------------------
bool maze::isDestination(int pos_row, int pos_col, int destination_row, int destination_col){
    if(pos_row == destination_row && pos_col == destination_col){
        return true;
    }
    return false;
}




//-------------------------------------------------------------------------
// Function Name : thankYou
// Purpose       : display the solution path of maze
//-------------------------------------------------------------------------
void maze::thankYou(){
    cout << "Thank you for your playing!" << endl;
}





#endif /* MAZE_H_ */
