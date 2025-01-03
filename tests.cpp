#include <iostream>
#include "tests.hpp"
#include "maze.hpp"
#include "fstream"

using namespace std;

void testValidMaze(){
    Maze maze;
    string filename = "test_valid_maze.txt";

    // Create a valid maze file
    ofstream file(filename);
    file << "#S###\n";
    file << "#...#\n";
    file << "##..#\n";
    file << "#E..#\n";
    file.close();

    // Load the maze
    if (maze.loadFromFile(filename)) {
        cout << "Test Valid Maze: PASSED\n";
    } else {
        cout << "Test Valid Maze: FAILED\n";
    }
}


void testInvalidCharacters(){
    Maze maze;
    string filename = "test_invalid_chars.txt";

    // Create a maze with invalid characters
    ofstream file(filename);
    file << "#S###\n";
    file << "#...#\n";
    file << "##..@\n"; // Invalid character '@'
    file << "#E..#\n";
    file.close();

    // Load the maze
    if (!maze.loadFromFile(filename)) {
        cout << "Test Invalid Characters: PASSED\n";
    } else {
        cout << "Test Invalid Characters: FAILED\n";
    }
}


void testMultipleStartEnd(){
    Maze maze;
    string filename = "test_multiple_start_end.txt";

    // Create a maze with multiple 'S' and 'E'
    ofstream file(filename);
    file << "#S###\n";
    file << "#...#\n";
    file << "##.S#\n"; // Additional start
    file << "#E.E#\n"; // Additional end
    file.close();

    // Load the maze
    if (!maze.loadFromFile(filename)) {
        cout << "Test Multiple Start and End: PASSED\n";
    } else {
        cout << "Test Multiple Start and End: FAILED\n";
    }
}


void testSolveMaze(){
    Maze maze;
    string filename = "test_solve_maze.txt";

    // Create a solvable maze
    ofstream file(filename);
    file << "#S###\n";
    file << "#...#\n";
    file << "##..#\n";
    file << "#E..#\n";
    file.close();

    // Load and solve the maze
    if (maze.loadFromFile(filename) && maze.Solve()) {
        cout << "Test Solve Maze: PASSED\n";
    } else {
        cout << "Test Solve Maze: FAILED\n";
    }
}


void testUnsolvableMaze(){
    Maze maze;
    string filename = "test_unsolvable_maze.txt";

    // Create an unsolvable maze
    ofstream file(filename);
    file << "#S###\n";
    file << "#.#.#\n";
    file << "##.#E\n"; // 'E' is isolated
    file.close();

    // Load and attempt to solve the maze
    if (maze.loadFromFile(filename) && !maze.Solve()) {
        cout << "Test Unsolvable Maze: Passed\n";
    } else {
        cout << "Test Unsolvable Maze: Failed\n";
    }
}


void testSaveToFile(){
    Maze maze;
    string inputFile = "test_save_maze.txt";
    string outputFile = "test_save_maze_output.txt";

    // Create a solvable maze
    ofstream file(inputFile);
    file << "#S###\n";
    file << "#...#\n";
    file << "##..#\n";
    file << "#E..#\n";
    file.close();

    // Load, solve, and save the maze
    if (maze.loadFromFile(inputFile) && maze.Solve()) {
        if (maze.saveToFile(outputFile)) {
            cout << "Test Save to File: PASSED\n";
        } else {
            cout << "Test Save to File: FAILED\n";
        }
    } else {
        cout << "Test Save to File: FAILED\n";
    }
}

void testerMain(){
    cout << "Running tests...\n";
    cout << "Testing valid maze...\n";
    testValidMaze();
    cout << "\nTesting invalid characters...\n";
    testInvalidCharacters();
     cout << "\nTesting multiple start and end...\n";
    testMultipleStartEnd();
    cout << "\nTesting solve maze...\n";
    testSolveMaze();
    cout << "\nTesting unsolvable maze...\n";
    testUnsolvableMaze();
    cout << "\nTesting save to file...\n";
    testSaveToFile();
}