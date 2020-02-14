#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
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
/// \param height
/// \param width
/// \param maze
void PrintMaze(int height, int width,char maze[][100]){
    clear();
    for (int i = 0; i <height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout<<maze[i][j];
        }
            cout<<endl;
    }
}



void MazeSolver(char maze[][100], int height, int width,int StartPoint[],int EndPoint[]){
    PrintMaze(height,width,maze);
    int Player_Position[]={StartPoint[0],StartPoint[1]};
    maze[1][3]=Player;
}
int main() {
    //Declaring map
    string maze_URL="..\\Maps\\maze2.txt";
    //Declaring real size
    int Height=GetHeight(maze_URL);
    int  Width=GetWidth(maze_URL);
    //Loading in the map
    char maze[100][100];
    FillArray(maze_URL, maze );
    //Cords
    int StartPoint[]={1,0};
    int EndPoint[]={Height-2,Width-1};
    maze[EndPoint[0]][EndPoint[1]]='#';
    maze[StartPoint[0]][StartPoint[1]]='#';
    PrintMaze(Height,Width,maze);
    MazeSolver(maze,Height,Width,StartPoint,EndPoint);
    return 0;
}


