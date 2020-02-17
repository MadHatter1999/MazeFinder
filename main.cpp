#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include "stack.h"
#include "stack"
using namespace std;

#define Player '#';
#define H_WALL '-';
#define V_WALL '|';
#define WALL '+';





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
    for (int i = 0; i < 25; ++i) {
        cout<<'\n';
    }
}

/// Prints Maze
/// \param height of maze INT
/// \param width of maze INT
/// \param maze array of maze Pointer to a 100,100 array
void PrintMaze(int height, int width,char maze[][100]){
    clear();
    for (int i = 0; i <height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout<<maze[i][j];
        }
            cout<<endl;
    }
}


void OutputMazeTo_TXT(){

}

void MazeSolver(char maze[][100], int height, int width,Point StartPoint,Point EndPoint) {

    enum Direction {
        North = 0, East = 1, South = 2, West = 3
    };

    //start stack
    Stack stack = Stack();

    maze[1][3] = Player;
    //Flag for finishing maze
    bool has_solved = false;
    //adding the first move to the stack of awesomeness
    stack.Push(StartPoint);
    Point Player_Position = StartPoint;
    while (!has_solved) {
        Player_Position.col+=1;
        maze[Player_Position.row][Player_Position.col]=Player;
        PrintMaze(height,width,maze);
        if(Player_Position.col==width){
            break;
        }
    }
    }
    int main() {

        //Declaring map
        string maze_URL = "..\\Maps\\maze2.txt";
        //Declaring real size
        int Height = GetHeight(maze_URL);
        int Width = GetWidth(maze_URL);
        //Loading in the map
        char maze[100][100];
        FillArray(maze_URL, maze);
        //Cords
        Point StartPoint = {1, 0};
        Point EndPoint = {Height - 2, Width - 1};
        MazeSolver(maze, Height, Width, StartPoint, EndPoint);


        return 0;
    }


