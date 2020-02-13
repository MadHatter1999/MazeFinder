#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX_Size 100;
using namespace std;

int M_S=100;
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

void FillArray(int height,int width,string url, char multiarray[][100]) {
    ifstream myFile;
    myFile.open(url);
    if(myFile.is_open()){
        for (int i = 0; i < height ; ++i) {
            int subIndex=0;
            for (int j = 0; j < width; ++j) {
                    multiarray[i][j]='#';
                    subIndex=j+1;
            }
            multiarray[i][subIndex]='\n';
        }
    } else{
        cout<<"FAILED TO OPEN FILE"<<endl;
    }


}

void PrintMaze(int height, int width,char maze[][100]){
    for (int i = 0; i <height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout<<maze[i][j];
        }
            cout<<endl;
    }
    cout<<"Test 2.5 Complete"<<endl;
}
int main() {
    //declaring Max size
    const int MAX_W=MAX_Size;
    const int MAX_H=MAX_Size;
    //Declaring map
    string maze_URL="..\\Maps\\maze2.txt";
    //Declaring real size
    int Height=GetHeight(maze_URL);
    int  Width=GetWidth(maze_URL);
    char maze[100][100];
    FillArray(Height, Width,maze_URL, maze );
    PrintMaze(Height,Width,maze);


    cout<<"Height of Maze: "<<GetHeight(maze_URL)<<endl;
    cout<<"Width of Maze: "<<GetWidth(maze_URL)<<endl;




    return 0;
}


