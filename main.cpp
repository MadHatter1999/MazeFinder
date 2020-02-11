#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//#define width 51;
//#define height 51;

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


int main() {
   const string maze_URL="..\\Maps\\maze2.txt";
    int Height=GetHeight("..\\Maps\\maze3.txt");
    int  Width=GetWidth("..\\Maps\\maze3.txt");
    cout<<"Height of Maze: "<<GetHeight(maze_URL)<<endl;
    cout<<"Width of Maze: "<<GetWidth(maze_URL)<<endl;




    return 0;
}


