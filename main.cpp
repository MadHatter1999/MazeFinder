#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#define MAX_Size 100;

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

void FillArray(string url, char* &array,int height,int width) {
    ifstream myFile;
    myFile.open(url);
    if(myFile.is_open()){

    } else{
        cout<<"FAILED TO OPEN FILE"<<endl;
    }

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
    char *maze[MAX_H][MAX_W];

    for (int i = 0; i < Height; ++i) {
        for (int j = 0; j < Width; ++j) {
            cout<<j;
        }
        cout<<endl;
    }
    cout<<"Height of Maze: "<<GetHeight(maze_URL)<<endl;
    cout<<"Width of Maze: "<<GetWidth(maze_URL)<<endl;




    return 0;
}


