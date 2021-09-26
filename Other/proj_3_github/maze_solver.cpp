#include <iostream>

#include "map1.h"
//#include "map2.h"
//#include "map3.h"

const char DESTINATION = 'd';
const char START = 's';
const char PORTAL = 'p';
const char PATH = ' ';
const char WALL = '#';
const char VISITED = '@';
const char LEFT = '<';
const char RIGHT = '>';
const char UP = '^';
const char DOWN = 'V';

using namespace std;

bool find_path_goes_right_only(int row, int col, char maze[ROW][COL])
{

	cout << "(" << row << ", " << col << ")" << endl;
	if (maze[row][col]== DESTINATION){
		return true;
	}
	if (maze[row][col] == WALL){
		return false;
	}
	else
		maze[row][col] = VISITED;
		return find_path_goes_right_only(row, col+1,maze);

}


bool find_path_basic(int row, int col, char maze[ROW][COL])
{
		if (maze[row][col]== DESTINATION){
				return true;
			}
		if (maze[row][col] == WALL || maze[row][col] == PORTAL || maze[row][col] == VISITED ){
				return false;
		   }
		else{
			maze[row][col] = VISITED;
				if (find_path_basic(row, col+1, maze))
					return true;

				if (find_path_basic(row+1, col, maze))
					return true;

				if (find_path_basic(row-1, col, maze))
					return true;

				if(find_path_basic(row, col-1, maze))
					return true;

				maze[row][col] = PATH;
				return false;
		}
}


bool find_path_with_direction(int row, int col, char maze[ROW][COL])
{
	if (maze[row][col]== DESTINATION){
			return true;
		}
	if (maze[row][col] == WALL || maze[row][col] == PORTAL || maze[row][col] == VISITED ){
			return false;
	   }
	else{
		maze[row][col] = VISITED;
			if (find_path_with_direction(row, col+1, maze)){
				maze[row][col] = RIGHT;
				return true;}

			if (find_path_with_direction(row+1, col, maze)){
				maze[row][col] = DOWN;
				return true;}

			if (find_path_with_direction(row-1, col, maze)){
				maze[row][col] = UP;
				return true;}

			if(find_path_with_direction(row, col-1, maze)){
				maze[row][col] = LEFT;
				return true;}

			maze[row][col] = PATH;
			return false;
	}

}


bool find_path_within_fixed_steps (int row, int col, char maze[ROW][COL], int step)
{
	if (maze[row][col]== DESTINATION){
						return true;
	}
	if (step<=0){
		return false;}

	if (maze[row][col] == WALL || maze[row][col] == PORTAL || maze[row][col] == VISITED ){
						return false;
				   }
				else{
					maze[row][col] = VISITED;
						if (find_path_within_fixed_steps(row, col+1, maze,--step))
							return true;

						if (find_path_within_fixed_steps(row+1, col, maze,--step))
							return true;

						if (find_path_within_fixed_steps(row-1, col, maze,--step))
							return true;

						if(find_path_within_fixed_steps(row, col-1, maze,--step))
							return true;

						maze[row][col] = PATH;
						return false;
				}
}


bool find_shortest_path(int row, int col, char maze[ROW][COL])
{
	for (int i = ROW*COL; i>=0; i--){
		if (!find_path_within_fixed_steps(row, col, maze,i)){
			return find_path_within_fixed_steps(row, col, maze,i+1);
		}


		for(int x =0; x <= ROW; x++){
			for(int y =0; y <= COL; y++){
			if (maze[x][y]== VISITED){
				maze[x][y] = PATH;
			}
		}
	}

}
	return false;
}


bool find_path_with_portal(int row, int col, char maze[ROW][COL])
{
	if (maze[row][col]== DESTINATION)
					return true;

	if (maze[row][col] == WALL || maze[row][col] == VISITED )
					return false;
			else{

				if (maze[row][col]== PORTAL){
					maze[row][col] = VISITED;
							for (int i = 0; i<=ROW; i++){
								for (int j = 0; j<=COL; j++){
									if ((maze[i][j]==PORTAL) && ((i!=row) || (j!=col))){
										row = i;
										col = j;
									}
								}
							}
					}

				maze[row][col] = VISITED;

					if (find_path_with_portal(row, col+1, maze))
						return true;

					if (find_path_with_portal(row+1, col, maze))
						return true;

					if (find_path_with_portal(row-1, col, maze))
						return true;
					if(find_path_with_portal(row, col-1, maze))
						return true;

					maze[row][col] = PATH;
					return false;
			}

}

/**
 * A function that helps print the maze
 */
void print_maze(const char maze[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			cout << maze[i][j];
		cout << endl;
	}
}



/**
 * Main function
 */
int main()
{

	char my_maze[ROW][COL];
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			my_maze[i][j] = MAZE[i][j];

	print_maze(my_maze);
	cout << endl;

	char input;
	cout << "Please choose the following path finder" << endl;
	cout << "(R)ight Only, (B)asic, (D)irection Mode, (S)hortest Path, (P)ortal" << endl;
	cin >> input;
	bool result = false;
	switch (input)
	{
	case 'R': //Part 1
	case 'r':
		result = find_path_goes_right_only(START_ROW, START_COL, my_maze);
		//print the maze
		print_maze(my_maze);
		break;
	case 'B':
	case 'b':
		result = find_path_basic(START_ROW, START_COL, my_maze);
		break;
	case 'D':
	case 'd':
		result = find_path_with_direction(START_ROW, START_COL, my_maze);
		break;
	case 'S':
	case 's':
		result = find_shortest_path(START_ROW, START_COL, my_maze);
		break;
	case 'P':
	case 'p':
		result = find_path_with_portal(START_ROW, START_COL, my_maze);

		break;
	default:
		cout << "Invalid Choice";
		return 0;
	}
	if (!result)
		cout << "No path found";
	else
		print_maze(my_maze);

	// to hold the program in windows mode
	char held;
	cout << endl << "Enter a character to quit" << endl;
	cin >> held;

	return 0;
}
