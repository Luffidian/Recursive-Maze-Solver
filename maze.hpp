#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>


class Maze {

    private:

        // uses a 2d vector for the sake of resizing
        std::vector<std::vector<char>> grid;
        int startRow, startCol;
        int endRow, endCol;

        std::string FName;

        // finds the Start and End block of each maze file it calls
        bool findStartAndEnd();

        // makes sure the maze is formatted correctly
        bool validate();

        // this function is created because solve can't function without the recursive call and it uses startRow and startCol, but they can't be used as arguments for the function, but they can be used in another function call
        bool SolveHelper(int x, int y); 


    public:

        // initializes an empty maze
        Maze(): startRow(-1), startCol(-1), endRow(-1), endCol(-1){};

        // uses char constants for the block types
        const char WALL = '#';
        const char OPEN = '.';
        const char START = 'S';
        const char END = 'E';
        const char VISITED = '*';

        // displays the maze
        void display() const;
        
        // calls findStartAndEnd() and then uses SolveHelper
        bool Solve();

        // saves the current maze to the file
        bool saveToFile(const std::string& filename);

        // initializes the grid of the maze
        bool loadFromFile(const std::string& filename);

        // allows the user to create a maze 
        void createMaze();

        // takes in a file with a maze and displays the root at which it solved the maze
        void solveAndDisplay();
};