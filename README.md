## Work Log

### Instructions

> Each time you work on the project, you will need to both:
> * make and push a commit of your progress via git
> * write a summary of what you worked on during that session

Do that here! Think of the summary as a more detailed commit message.
Did you have to make a decision about how your code would be organized?
Did you diagnose and fix a challenging bug?
Did you complete one of your project milestones?
It doesn't need to be long, but write a little bit about your process.

**Important:**
* You **must** do this each time you work on the project.
* You **must** have more than one log entry and more than one commit to Complete this project.
  * (It's fine if multiple commits from a single period of work are described in one entry.)
* This helps convince me that you actually did your own work.
* I really want to make sure this is clear:
  **You MUST fill out the log WHILE you work.**
  If you fill the log out retroactively, at the end,
  I **will not** give you a *Completed* for this assignment.

### Log Entries

#### 12/6/24
* created a main function and a file skeleton
* created the 'maze.hpp' file that has different functions 
* The maze class uses an enum class with different characters to represent a maze file
* The maze class will have solve function, a saveToFile function, a loadFromFile function, and a print function
* The maze is stored in a 2d vector that I learned to write in CS1

#### 12/7/24
* began writing the functions
* going to write first the saveToFile, loadFromFile, and display functions
* saveToFile and loadFromFile required trial and error regarding use of getline and 2d vector
* issue I've ran into is that writing an enum class would require me to write function overloads and that's honestly just not worth the effort when I can make these into const char variables instead
* I changed the enum class into const char variables. An enum would make my code look more polished, but ultimately speaking, I don't feel the need to make it 

#### 12/10/24
* began writing the Solve function
* Conceptually, it doesn't seem very difficult. All I need is for the maze to traverse the open spots, mark visited areas, and then if a dead end is reached, I should stop the recursive call
* I've also written a validate function that validates whether or not a maze is valid to solve in the first place

#### 12/13/24
* come back to the solve function. I've realized that I can't write a recursive call unless there are actual arguments for said recursive call
* This is an issue because the startColumn and startRow members aren't accessible through the main functions
* So I've opted to write a solveHelper function that'd take in startColumn and StartRow as arguments in my solve function
* also written a private helperfunction that finds startColumn and startRow before I call solveHelper
* I've also began to write a solveAndDisplay function that'll display the maze path 

#### 12/15/24
* written a few tests that load mazes into files and I test for regular error cases like invalid character input
* wrote main and realized that you can't have variables in a switch case and put them outside of it
* ran a few tests and figured out that my solveHelper had a few really stupid syntax errors that I've now edited and rectified
* needed to edit my solve function so that it'll backtrack on any failed paths so that my solveAndDisplay function would work as intended and display only the correct path

#### 12/16/24
* I've written a user maze creation tool that allows the user to input how many rows and columns they want and checks whether or not any characters typed in aren't valid
* The code for that is somewhat derivative of the earlier code wrote, so there weren't errors thankfully

#### 12/17/24
* written main into a loop so that you can create a maze and then display it properly without needing to run the program again
* wrote comments where I could potentially explain more things in general

# **Welcome to the Maze Solver**

## **Introduction**

The Maze Solver allows users to input a maze, get it solved, and then display the solved maze.

## **Compilation**
To compile the program run:
g++ *.cpp

## **Running the program**
To execute the program:
./a.out

## **Menu Options**

After starting the program, you will see a menu with different options:

1. **Tests**
This tests the functionality of the program by in large.

2. **Inputting a maze**
This allows the user to create a maze. You will be asked to specifya filename for the maze the amount of rows and columns that will be needed for the maze. You will then be asked to write a maze into the console and it will be saved.

3. **solving a maze.**
This allows the user to specify a filename that a maze is stored in and get it solved by the program. It will display the original maze and then showcase the solved maze with a path.

4. **exit**
This terminates the program.

# Running the program
To run the program, 
go to the console after code compilation and write: ./a.out

## Sample output

### Tests

```
Choose between 3 choices.
1. Tests
2. inputting a maze
3. solving a maze
4. exit
Choice: 1
Running tests...
Testing valid maze...
Test Valid Maze: PASSED

Testing invalid characters...
Error: Invalid character '@' found in maze.
Error : invalid maze structure
Test Invalid Characters: PASSED

Testing multiple start and end...
Error: Maze must contain exactly one starting point (S). Found 2.
Error : invalid maze structure
Test Multiple Start and End: PASSED

Testing solve maze...
Test Solve Maze: PASSED

Testing unsolvable maze...
Test Unsolvable Maze: Passed

Testing save to file...
Test Save to File: PASSED
Choose between 3 choices.
1. Tests
2. inputting a maze
3. solving a maze
4. exit
Choice: 4
```

## Inputting and Solving a Maze

```
Choose between 3 choices.
1. Tests
2. inputting a maze
3. solving a maze
4. exit
Choice: 2
Enter the number of rows: 4
Enter the number of columns: 5
Enter the filename to save the maze: userMaze.txt
Enter your maze row by row. Use the following characters:
'#' for walls, '.' for open paths, 'S' for start, 'E' for end.
Row 1: ##S#
Error: Row must have exactly 5 characters.
Row 1: ##S##
Row 2: #...#
Row 3: ###.#
Row 4: ###E#
Maze saved successfully to userMaze.txt!
Choose between 3 choices.
1. Tests
2. inputting a maze
3. solving a maze
4. exit
Choice: 3
Enter the maze file name: userMaze.txt
Original Maze:
##S##
#...#
###.#
###E#

Maze solved! Here's the path:
##*##
#.**#
###*#
###E#

Do you want to save the solved maze to a file? (y/n): y
Enter the filename to save the solved maze: solvedMaze.txt
Solved maze successfully saved to solvedMaze.txt!
Choose between 3 choices.
1. Tests
2. inputting a maze
3. solving a maze
4. exit
Choice: 4
```

## Large Maze for fun!(and testing)

```
Choose between 3 choices.
1. Tests
2. inputting a maze
3. solving a maze
4. exit
Choice: 3
Enter the maze file name: maze.txt
Original Maze:
####S#
#.#..#
#...##
#.#..#
#..###
##...#
#..#.#
####E#

Maze solved! Here's the path:
####*#
#.#**#
#***##
#*#..#
#**###
##***#
#..#*#
####E#

Do you want to save the solved maze to a file? (y/n): n
Choose between 3 choices.
1. Tests
2. inputting a maze
3. solving a maze
4. exit
Choice: 4
```

