#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
void openMaze(string url){
    ifstream myFile;
    myFile.open(url);
    string line;
    if(myFile.is_open()){
        cout<<"opened"<<endl;
        while(getline(myFile,line)){
            cout<<line<<endl;
        }


    } else{
        std::cout<<"failed to opened"<<std::endl;
    }
}
int main() {
    string maze_URL="..\\Maps\\maze.txt";
    openMaze(maze_URL);
    return 0;
}


