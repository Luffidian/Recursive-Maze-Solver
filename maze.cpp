#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "maze.hpp"

using namespace std;

bool Maze::loadFromFile(const string& filename){
    ifstream file(filename);
    FName = filename;


    grid.clear();
    string line;

    // read each row
    while(getline(file, line)){
        vector<char> row(line.begin(), line.end());
        grid.push_back(row);
    }

    //make sure that the maze is validated
    if(!validate()){
        cerr << "Error : invalid maze structure" << endl;
        return false;
    }

    file.close();
    return true;
}

void Maze::display() const{
    for(const auto& row : grid){
        for(const auto& cell : row){
            cout << cell;
        }
        cout << endl;
    }
}

bool Maze::saveToFile(const string& filename){
    ofstream file(filename);
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            file << cell; // Output each character 
        }
        file << '\n'; // Newline at the end of each row
    }

    file.close();

    return file.good();
}

bool Maze::Solve(){
    findStartAndEnd();
    return SolveHelper(startRow, startCol);
}


bool Maze::SolveHelper(int x, int y){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return false; // bounds checking
    if(grid[x][y] == WALL || grid[x][y] == VISITED) return false; // return false if wall is ran itno
    if(grid[x][y] == END) return true; // return true if maze is solved 

    grid[x][y] = VISITED; // mark as visited

    // traverse accordingly
    if(SolveHelper(x + 1, y) || 
    SolveHelper(x - 1, y) || 
    SolveHelper(x, y + 1) ||
    SolveHelper(x, y - 1)) { 
        return true;
    }

    grid[x][y] = OPEN;
    return false;
}

bool Maze::findStartAndEnd(){
    // iterate to make sure start and end are found
    for(int x = 0; x < grid.size(); x++){
        for(int y = 0; y < grid[x].size(); y++){
            if(grid[x][y] == START){
                startRow = x;
                startCol = y;
            } else if(grid[x][y] == END){
                endRow = x;
                endCol = y;
            }
        }
    }
    // Ensure both start and end are found
    if (startRow == -1 || startCol == -1) {
        cout << "Error: No starting point 'S' found in the maze." << endl;
        return false;
    }
    if (endRow == -1 || endCol == -1) {
        cout << "Error: No ending point 'E' found in the maze." << endl;
        return false;
    }
    return true;
}

bool Maze::validate(){
    if (grid.empty()) {
        cerr << "Error: Maze is empty." << endl;
        return false;
    }

    int numRows = grid.size();
    int numCols = grid[0].size();

    // makes sure that there are not more than one start or end
    int startCount = 0;
    int endCount = 0;

    for (int i = 0; i < numRows; ++i) {
        if (grid[i].size() != numCols) {
            cerr << "Error: Maze rows are not of consistent length." << endl;
            return false;
        }

        for (const char& cell : grid[i]) {
            switch (cell) {
                case '#':   // Valid wall
                case '.':   // Valid open path
                case 'S':  // Valid start
                    startCount += (cell == 'S');
                    break;
                case 'E':    // Valid end
                    endCount += (cell == 'E');
                    break;
                default:
                    cerr << "Error: Invalid character '" << cell << "' found in maze." << endl;
                    return false;
            }
        }
    }

    if (startCount != 1) {
        cerr << "Error: Maze must contain exactly one starting point (S). Found " << startCount << "." << endl;
        return false;
    }

    if (endCount != 1) {
        cerr << "Error: Maze must contain exactly one endpoint (E). Found " << endCount << "." << endl;
        return false;
    }

    return true;
}

void Maze::createMaze(){
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    string filename;
    cout << "Enter the filename to save the maze: ";
    cin >> filename;


    cin.ignore();
    vector<string> maze(rows);

    cout << "Enter your maze row by row. Use the following characters:\n";
    cout << "'#' for walls, '.' for open paths, 'S' for start, 'E' for end.\n";

    for (int i = 0; i < rows; ++i) {
        while (true) {
            cout << "Row " << (i + 1) << ": ";
            getline(cin, maze[i]);

            // Validate input length
            if (maze[i].length() != cols) {
                cout << "Error: Row must have exactly " << cols << " characters.\n";
                continue;
            }

            // Validate input characters
            bool valid = true;
            for (char c : maze[i]) {
                if (c != '#' && c != '.' && c != 'S' && c != 'E') {
                    cout << "Error: Invalid character '" << c << "'. Please use only '#', '.', 'S', or 'E'.\n";
                    valid = false;
                    break;
                }
            }

            if (valid) break;
        }
    }

    // Ensure there's exactly one start and one end
    int startCount = 0, endCount = 0;
    for (const string& row : maze) {
        for (char c : row) {
            if (c == START) {
                ++startCount;
            } else if (c == END) {
                ++endCount;
            } else if (c != WALL && c != OPEN) {
                cerr << "Invalid character '" << c << "' found in maze." << endl;
                return; // Invalid character
            }
        }
    }

    if (startCount != 1 || endCount != 1) {
        cout << "Error: Maze must have exactly one 'S' (start) and one 'E' (end).\n";
        return;
    }

    // Save maze to file
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file for writing.\n";
        return;
    }

    for (const string& row : maze) {
        file << row << '\n';
    }

    file.close();
    cout << "Maze saved successfully to " << filename << "!\n";
}

void Maze::solveAndDisplay() {
    string filename;
    cout << "Enter the maze file name: ";
    cin >> filename;

    // Load the maze from the file
    if (!loadFromFile(filename)) {
        cerr << "Error: Could not load maze from file." << endl;
        return;
    }

    // Display the original maze
    cout << "Original Maze:" << endl;
    display(); // This function displays the maze as is

    // Solve the maze
    if (Solve()) {
        cout << "\nMaze solved! Here's the path:" << endl;

        // Display the solved maze
        display(); // This will show the maze with the solution path marked

        char saveChoice;
        cout << "\nDo you want to save the solved maze to a file? (y/n): ";
        cin >> saveChoice;

        if (saveChoice == 'y' || saveChoice == 'Y') {
            string outputFilename;
            cout << "Enter the filename to save the solved maze: ";
            cin >> outputFilename;

            if (saveToFile(outputFilename)) {
                cout << "Solved maze successfully saved to " << outputFilename << "!" << endl;
            } else {
                cerr << "Error: Could not save the solved maze to file." << endl;
            }
        }
    } else {
        cout << "No solution found for the maze." << endl;
    }
}

