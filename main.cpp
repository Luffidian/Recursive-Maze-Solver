#include <iostream>
#include <string>
#include <fstream>
#include "maze.hpp"
#include "tests.hpp"

using namespace std;

int main(){
    char choice;
    Maze userMaze;
    Maze maze;


    while(choice != '4'){
        cout << "Choose between 3 choices." << endl;
        cout << "1. Tests\n";
        cout << "2. inputting a maze\n";
        cout << "3. solving a maze\n";
        cout << "4. exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch(choice){
            case '1':
                testerMain();
                break;
            case '2':
                userMaze.createMaze();
                break;
            case '3':
                maze.solveAndDisplay();
                break;
            case '4':
                break;
        }
    }
    return 0;
}