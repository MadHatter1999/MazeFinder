#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/// Gets the Vertical Demension from maze
/// \param url
/// \return
int GetHeight(string url){
    ifstream myFile;
    myFile.open(url);
    string line;
    int height=0;
    if(myFile.is_open()){
        while(getline(myFile,line)){
            height++;
        }
    } else{
        std::cout<<"failed to opened"<<std::endl;
    }
    myFile.close();
    return height;
}
/// Gets The Horizontal Demension from maze
/// \param url
/// \return
int GetWidth(string url){
    ifstream myFile;
    myFile.open(url);
    string line;
    int width=0;
    if(myFile.is_open()){
        while(getline(myFile,line)){
            width=line.length();
            break;
        }
    } else{
        std::cout<<"failed to opened"<<std::endl;
    }
    myFile.close();
    return width;
}

const int Height=GetHeight("..\\Maps\\maze3.txt");
const int  Width=GetWidth("..\\Maps\\maze3.txt");

int main() {
    string maze_URL="..\\Maps\\maze.txt";
    cout<<"Height of Maze: "<<GetHeight(maze_URL)<<endl;
    cout<<"Width of Maze: "<<GetWidth(maze_URL)<<endl;




    return 0;
}


