#include <stdio.h>
#include<stdbool.h>

int solveMaze(char **maze, const int HT, const int WD, int a, int b); 
void printM(char **maze, const int HT, const int WD); 

int main()
{
	char mazeStr[] =
			"  ##############"
		    "#     #     ####"
		    "# ####* ### ####"
		    "#    ###### ####"
		    "#### # #### ####"
		    "#    # #### ####"
		    "#### # #### ####"
		    "####        ####"
		    "################";
	const int HT = 9;
	const int WD = 16;
	char *maze[HT];

	for (int i=0; i<HT ; i++)
		maze[i]=&mazeStr[i*WD];

	solveMaze(maze, HT, WD, 0, 0);
	printM(maze, HT, WD);

	return 0;
}

int solveMaze(char **maze, const int HT, const int WD, int a, int b)
{
	if(a < 0 || a >= WD || b < 0 || b >= HT) 
		return 0; 
	if(maze[b][a] == '*') 
		return 1; 
	if(maze[b][a] == '#' || maze[b][a] == '.') 
		return 0; 

	maze[b][a] = '.'; 

	if(solveMaze(maze, HT, WD, a, b - 1) == 1) 
		return 1; 	
	if(solveMaze(maze, HT, WD, a + 1, b) == 1) 
		return 1; 
	if(solveMaze(maze, HT, WD, a, b + 1) == 1) 
		return 1; 
	if(solveMaze(maze, HT, WD, a - 1, b) == 1) 
		return 1; 
	maze[b][a] = ' '; 
	return 0;
}

void printM(char **maze, const int HT, const int WD){
    for (int i = 0; i < HT; i++){
	for(int j = 0; j < WD - 1; j++)
	  printf("%c", maze[i][j]);
	printf("%c\n", maze[i][WD-1]);
    }
}
