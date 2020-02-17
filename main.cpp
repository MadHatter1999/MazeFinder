#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include "Stack.h"
#include "stack"
using namespace std;



enum Direction {
    Up = 0, Right = 1, Down = 2, Left = 3
};
enum mazeDetails{
    Empty = ' ', Used = '#', Dead = 'D'
};


/// Gets the Vertical Demension from maze
/// \param url
/// \return
int GetHeight(string url){
    ifstream myFile;
    myFile.open(url);
    string line;
    int Height=0;
    if(myFile.is_open()){
        while(getline(myFile,line)){
            Height++;
        }
    } else{
        std::cout<<"failed to opened"<<std::endl;
    }
    myFile.close();
    return Height;
}
/// Gets The Horizontal Demension from maze
/// \param url
/// \return
int GetWidth(string url){
    ifstream myFile;
    myFile.open(url);
    string line;
    int Width=0;
    if(myFile.is_open()){
        while(getline(myFile,line)){
            Width=line.length();
            break;
        }
    } else{
        std::cout<<"failed to opened"<<std::endl;
    }
    myFile.close();
    return Width;
}


/// Fills Array with maze from file
/// \param url
/// \param multiarray
void FillArray(string url, char multiarray[][100]) {
    ifstream myFile;
    myFile.open(url);
    if(myFile.is_open()){
        string TMP_Line;
        int index=0;
        while(getline(myFile, TMP_Line)){
            //Converting the String to Char Array
            char *Line= new char[TMP_Line.size()+1];
            strcpy(multiarray[index],TMP_Line.c_str());
            index++;
        }
    } else{
        cout<<"FAILED TO OPEN FILE"<<endl;
    }


}

/// Clears the Screen
void clear(){
    for (int i = 0; i < 10; ++i) {
        cout<<'\n';
    }
}

/// Prints Maze
/// \param height of maze INT
/// \param width of maze INT
/// \param maze array of maze Pointer to a 100,100 array
void PrintMaze(int height, int width,char maze[][100]){
    for (int i = 0; i <height; ++i) {
        for (int j = 0; j < width; ++j) {
            char placeHolder;
            if(maze[i][j]=='D'){
                placeHolder=Empty;
            }
            else{
                placeHolder=maze[i][j];
            }
            cout<<placeHolder;
        }
            cout<<endl;
    }
}
/// Checks if Wall is in the move you wish to make is valid
/// \param Player_Pos
/// \param Dir
/// \param maze
/// \return
bool Check_Move(Point *Player_Pos,Direction Dir,char maze[][100]){
    switch(Dir){
        case Up:
            return (maze[Player_Pos->row - 1][Player_Pos->col]==Empty);
        case Right:
            return (maze[Player_Pos->row][Player_Pos->col+1]==Empty);
        case Down:
            return (maze[Player_Pos->row+1][Player_Pos->col]==Empty);
        case Left:
            return (maze[Player_Pos->row][Player_Pos->col-1]==Empty);
    }
}
/// This here moves player depending on direction
/// \param maze
/// \param player
/// \param stack
/// \param Dir
void Move_Player(char maze[][100],Point *player, Stack *stack, Direction Dir){
    stack->Push(*player);
    maze[player->row][player->col]=Used;
    switch(Dir){
        case Up:
            player->row-=1;
            break;
        case Right:
            player->col+=1;
            break;
        case Down:
            player->row+=1;
            break;
        case Left:
            player->col-=1;
            break;
    }
}
///OutPuts Mazes
/// to Text File
/// \param maze
/// \param File
/// \param Height
/// \param Width
void OutputMazeTo_TXT(char maze[][100],string File,int Height,int Width){
    string Dir="..\\Solved\\";
    ofstream Solution;
    Solution.open(Dir+File);
    for (int i = 0; i < Height; i++) {
        for (int x = 0; x < Width; x++) {
            char PlaceHolder;
            if(maze[i][x]=='D'){
                PlaceHolder=' ';
            }
            else{
                PlaceHolder=maze[i][x];
            }
            Solution << PlaceHolder;
        }
        Solution<<"\n";
    }
    Solution.close();
}


/// Solves the maze
/// \param maze
/// \param height
/// \param width
/// \param StartPoint
/// \param EndPoint
/// \param File
void MazeSolver(char maze[][100], int height, int width,Point StartPoint,Point EndPoint,string File) {
    //start stack
    Stack stack = Stack();
    Point Player_Pos=StartPoint;
    while(!Player_Pos.equals(EndPoint)){
        //Direction checking
        if(Check_Move(&Player_Pos,Right,maze)){
            Move_Player(maze,&Player_Pos,&stack,Right);
            continue;
        }
        if(Check_Move(&Player_Pos,Down,maze)){
            Move_Player(maze,&Player_Pos,&stack,Down);
            continue;
        }
        if(Check_Move(&Player_Pos,Left,maze)){
            Move_Player(maze,&Player_Pos,&stack,Left);
            continue;
        }
        if(Check_Move(&Player_Pos,Up,maze)){
            Move_Player(maze,&Player_Pos,&stack,Up);
            continue;
        }

        //Back Tracking
        if(!stack.empty()){
            maze[Player_Pos.row][Player_Pos.col]=Dead;
            Player_Pos=stack.getTop();
            stack.Pop();
            continue;
        }

    }
    OutputMazeTo_TXT(maze,File,height,width);
    PrintMaze(height,width,maze);
}
    int main() {
        cout<<"Welcome to Maze Solver"<<endl;

        string Dir="..\\Maps\\";
        cout<<"Maze"<<endl;
        string File="maze.txt";
        //Declaring map
        string maze_URL = Dir+File;
        //Declaring real size
        int Height = GetHeight(maze_URL);
        int Width = GetWidth(maze_URL);
        //Loading in the map
        char maze[100][100];
        FillArray(maze_URL, maze);
        //Cords
        Point StartPoint = {1, 0};
        Point EndPoint = {Height - 2, Width - 1};
        MazeSolver(maze, Height, Width, StartPoint, EndPoint,File);

        //Maze2
        cout<<"Maze2"<<endl;
        File="maze2.txt";
        maze_URL = Dir+File;
        Height = GetHeight(maze_URL);
        Width = GetWidth(maze_URL);
        FillArray(maze_URL, maze);
        EndPoint = {Height - 2, Width - 1};
        MazeSolver(maze, Height, Width, StartPoint, EndPoint,File);
        clear();

        //Maze 3
        cout<<"Maze3"<<endl;
        File="maze3.txt";
        maze_URL = Dir+File;
        Height = GetHeight(maze_URL);
        Width = GetWidth(maze_URL);
        FillArray(maze_URL, maze);
        EndPoint = {Height - 2, Width - 1};
        MazeSolver(maze, Height, Width, StartPoint, EndPoint,File);
        clear();

        //Maze 4
        cout<<"Maze4"<<endl;
        File="maze4.txt";
        maze_URL = Dir+File;
        Height = GetHeight(maze_URL);
        Width = GetWidth(maze_URL);
        FillArray(maze_URL, maze);
        EndPoint = {Height - 2, Width - 1};
        MazeSolver(maze, Height, Width, StartPoint, EndPoint,File);
        clear();

        //Maze X
        cout<<"MazeX"<<endl;
        File="mazex.txt";
        maze_URL = Dir+File;
        Height = GetHeight(maze_URL);
        Width = GetWidth(maze_URL);
        FillArray(maze_URL, maze);
        EndPoint = {Height - 2, Width - 1};
        MazeSolver(maze, Height, Width, StartPoint, EndPoint,File);

        return 0;
    }


