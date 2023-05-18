# IF184401_DAA_Q2_5025211015_5025211057_5025211254
## Anggota Kelompok
NRP | Nama |
--- | --- | 
5025211015 | Muhammad Daffa Ashdaqfillah |
5025211057 | Salsabila Fatma Aripa |
5025211254 | Yusna Millaturrosyidah | 

## Daftar Isi
- [About](#About)
- [Design](#Design)
- [Implementation](#Implementation)
- [Analysis](#Analysis)
- [Conclusion](#Conclusion)
- [Job Description and Contribution](#Job-Description-and-Contribution)

## About
This document is the documentation for the `Tic Tac Toe Project`, which is part of the `Quiz 2 Project` for the `Design and Analysis of Algorithms Course`.

**Leveling :** 
- Level 1: Two Player Game
In this level, two players take turns placing X's and O's on the game board until someone wins or the game ends in a draw. The game board is displayed on the screen, and players input their moves via the command line.

- Level 2: Player vs Bot
In this level, the player goes up against a computer-controlled opponent. The player can choose to go first or second. If the player goes first, they input their moves via the command line as in Level 1. If the player goes second, the computer will make the first move, and subsequent moves are made by the player and the computer in turn.

- Level 3: Player vs AI (Unbeatable)
This level introduces an AI opponent that is more difficult to beat than the bot in Level 3. The AI opponent uses an algorithm called minimax to determine the best move to make based on the current state of the game board.

**How to play :** 
To play the game, select the desired level from the main menu. In Levels 1, players input their moves via the command line. In Levels 2 and 3, the game board is displayed on the screen, and players input their moves using the keyboard.

In Level 2 and 3, the player can choose to go first or second.

The game ends when a player wins or the game ends in a draw. Players can   choose to play again or exit the game after each match.


## Design

## Implementation
**a. Minimax Algorithm :** 
The minimax algorithm is a well-known algorithm used in game theory and decision-making problems. It is a recursive function that simulates all possible moves that both the AI and the player can make, and assigns a score to each move based on the likelihood of winning the game. The function then chooses the move with the highest score for the AI.

In Tic Tac Toe, the algorithm is used in Level 3 to determine the best move for the AI opponent. The algorithm starts by checking if the current state of the game board is a winning state for either the AI or the player. If it is, it returns a score of 1 for a win, -1 for a loss, and 0 for a tie.
If the game is not in a winning state, the algorithm creates a tree of all possible moves that the AI and the player can make. The algorithm then recursively calls itself on each of the possible moves, alternating between maximizing the score for the AI and minimizing the score for the player. The score for each move is assigned based on the result of the recursive call, and the move with the highest score is chosen for the AI.

The `minimax()` function in the source code is the implementation of the minimax algorithm. It takes two arguments: depth, which represents the current depth of the game tree, and isMaximizingPlayer, which is a boolean value that represents whether the current player is the AI or the opponent.
The function first checks if the game is in a winning state, by calling the `result()` function. If the game is in a winning state, the function returns a score of 1 for a win, -1 for a loss, and 0 for a tie.

If the game is not in a winning state, the function creates a loop that iterates through all possible moves that can be made on the game board. For each possible move, the function simulates the move by updating the game board and calling itself recursively with the depth parameter increased by 1 and the isMaximizingPlayer parameter negated. The score for each move is then assigned based on the result of the recursive call.

If the isMaximizingPlayer parameter is true, the function chooses the move with the highest score. If the parameter is false, the function chooses the move with the lowest score. The function then undoes the move that was made on the game board and returns the chosen score.
The minimax algorithm uses backtracking to simulate the game board and undo moves that were made during the recursion. This allows it to evaluate all possible moves and determine the best one for the AI to make.

One important aspect of the minimax algorithm is pruning, which is the process of removing nodes from the game tree that are unlikely to lead to the optimal solution. This is done by using alpha-beta pruning, which is a technique that allows the algorithm to skip over branches of the tree that can be proven to be irrelevant to the final result.

The players are trying to maximize or minimize the others result: The AI is the "Maximizer" who tries to get the highest result per level The opponent is the "Minimizer" who tries to get the lowest result per level. 

**Tic Tac Toe minimax game illustration :**

![minimax](https://github.com/yusnaaaaa/IF184401_DAA_Q2_5025211015_5025211057_5025211254/assets/91377793/cd3a0db2-5ac0-41a6-afcb-3f85dca294d9)


**Complexity Time :**

As we traverse all levels of a tree and at each level, we need to generate all permutations of each node using DFS (Depth-First Search), we can conclude that the worst-case scenario is the only case that runs with a complexity of O(V+E) or O(b^d) for DFS (i.e., exploring the entire tree). Basically, the time complexity of the search using the Minimax Algorithm is the same as that of DFS.

![grafik minimax](https://github.com/yusnaaaaa/IF184401_DAA_Q2_5025211015_5025211057_5025211254/assets/91377793/7df5152e-7716-498f-a093-42ad03db1b17)


**b. Random value by time :** 

In level 2 of the game, where the player is playing against the bot, we use the rand() function to obtain random numbers. However, there is an adjustment to ensure that the generated numbers are truly different each time it is called.

srand(time(0)) is used before calling the rand() function to initialize the random number generator. This is done to ensure that each time the program is run, the random numbers generated by rand() will be different.

The rand() function itself uses an algorithm to generate a sequence of random numbers based on a specific seed value. This seed is the initial value used to start the algorithm. **If the seed is the same, the sequence of random numbers generated will be the same in every program execution.**

**By using srand(time(0)), the seed of rand() is set based on the current time.** Since time keeps changing, the seed will also change each time the program is run. This produces different sequences of random numbers in each program execution, providing better variation in the random number selection.

In the context of this game, rand() is used to select random positions on the game board. By using srand(time(0)), the selection of random positions will be more random and unpredictable each time the program is run.


## Analysis

### Libraries Used

Explanation : 
`Header file <stdio.h>` : This header file provides standard input/output functions such as printf() and scanf(), which are used in the program to display messages on the screen and receive input from the user. 

`Header file <time.h>` : This header file provides functions for manipulating time and date. In this program, this header file is used to generate random values when the computer player (Bot or AI) needs to make a move. 

`Header file <stdbool.h>` : This header file introduces the boolean data type (bool) and boolean constants (true and false). The boolean data type is used in this program to store truth values (true or false), which are used in logical conditions and program flow control. 

`Header file <stdlib.h>` : This header file provides general utility functions such as dynamic memory allocation (malloc() and free()) and other utility functions. In this program, this header file is used to use functions like rand() to generate random numbers. 

`Header file <string.h>` : This header file provides functions for string manipulation, such as strcpy() and strlen(). In this program, this header file is not directly used, so it may not be necessary in the context of this program.

### Array Board

Explanation : 
The line of code 
`char arr[3][3]= {'.','.','.', '.','.','.', '.','.','.'};` initializes a 2-dimensional character array named arr with a size of 3x3. The array is filled with the characters '.', representing empty spaces or placeholders.

This array is used as the game board for the Tic Tac Toe game. Each element in the array corresponds to a cell on the game board. The initial values of all elements are set to '.', indicating that the cells are initially empty.

As the game progresses, the elements in the arr array will be updated to hold the symbols 'X' or 'O' to represent the moves made by the players.

## void mainScreen() Function

Explanation : 
The function `void mainScreen()` is defined to display the main screen or menu of the Tic Tac Toe game. The main screen provides a clear and concise presentation of the game options, allowing the player to choose the desired level of gameplay.

### void gameBoard(char* P1, char* P2) Function

Explanation : 
The function `void gameBoard(char* P1, char* P2)` is defined to display the current state of the Tic Tac Toe game board.  The elements of the arr array are used to populate the game board. Each element represents a cell on the board, and its corresponding value is printed. 

The players' names and symbols are displayed below the game board. P1 corresponds to the first player's name, and P2 corresponds to the second player's name. The symbols 'X' and 'O' represent the moves made by the respective players. 

By calling this function during the game, the current state of the game board is visually presented to the players, allowing them to see the positions of their moves and the overall progress of the game.

### void init() Function

Explanation : 
The function `void init()` is defined to initialize or reset the Tic Tac Toe game board to its initial state. It sets all the elements of the arr array to the character '.', indicating empty spaces or placeholders. 

The function achieves this by using nested loops to iterate through each element of the 2-dimensional arr array. The outer loop iterates over the rows, and the inner loop iterates over the columns. For each element, the assignment statement arr[i][j]='.' is used to set its value to '.'. 

After executing this function, the game board will be reset to its original state, where all the cells are empty. This allows for a fresh start or a new game to be played on the board.

### Result Function

Explanation: 
The function char result() is defined to determine the current result or outcome of the Tic Tac Toe game. It analyzes the game board represented by the arr array and checks for winning conditions or a draw.

The function first checks for a winning condition in each row by comparing the values of 3 consecutive elements in the same row yakni (0, 1, 2). It iterates through each row using a for loop and checks if the three elements are equal to each other and not equal to '.', indicating that a player has made a move in that row. If a winning condition is found, the corresponding symbol is returned.

Next, the function checks for a winning condition in each column by comparing the values of three consecutive elements in the same column. It uses a similar logic as the row check but iterates through each column using a for loop. If a winning condition is found, the corresponding symbol is returned.

The function then checks for a winning condition in the diagonal from the top-left to the bottom-right. It compares the values of the three elements at positions (0, 0), (1, 1), and (2, 2). If a winning condition is found, the corresponding symbol is returned.

Finally, the function checks for a winning condition in the diagonal from the top-right to the bottom-left. It compares the values of the three elements at positions (0, 2), (1, 1), and (2, 0). If a winning condition is found, the corresponding symbol is returned.

If no winning condition is found after the previous checks, the function proceeds to check if the game board is full, indicating a draw. It uses nested loops to iterate through each element of the arr array. If an empty cell (denoted by '.') is found, the boolean variable cek is set to false, indicating that the board is not full. If the board is full, meaning all cells are filled, the function returns 'T' to represent a draw.

If none of the above conditions are met, the function returns '-', indicating that the game is still ongoing.

### Minimax Function

Explanation : 
The function int minimax(int depth, bool isMaximizing) implements the minimax algorithm, which is a recursive algorithm used to determine the optimal move in a game with perfect information. This function uses the minimax algorithm to recursively evaluate all possible moves and assign scores, ultimately returning the best score for the maximizing player or the worst score for the minimizing player at the current game state.

The function takes two parameters: depth, which represents the current depth in the game tree, and isMaximizing, a boolean flag indicating whether it is the maximizing player's turn or not.

The function first checks the result of the game by calling the result() function. If the result is 'O', it means the maximizing player (represented by 'O') has won, so the function assigns a score of 1 and returns it. If the result is 'X', it means the minimizing player (represented by 'X') has won, so the function assigns a score of -1 and returns it. If the result is 'T', it means the game is a draw, so the function assigns a score of 0 and returns it.

If none of the above conditions are met, the function proceeds to evaluate the possible moves.

If it is the maximizing player's turn (isMaximizing is true), the function initializes bestScore as a very low value (-1000) to track the highest score found. It then iterates through each cell of the game board represented by the arr array. If a cell is empty (denoted by '.'), it makes a move by assigning 'O' to that cell, and then recursively calls the minimax function with depth+1 and isMaximizing set to false to evaluate the opponent's turn.

After the recursive call, the move is undone by resetting the cell to '.'. The returned score is compared with bestScore, and if it is greater, bestScore is updated to the new higher score.

Finally, after iterating through all possible moves, the function returns bestScore, representing the highest possible score for the maximizing player.

If it is the minimizing player's turn (isMaximizing is false), the function follows a similar logic as above, but instead, it initializes bestScore as a very high value (1000) to track the lowest score found. It aims to find the move with the lowest possible score for the minimizing player.

The function iterates through each cell, makes a move with 'X', recursively calls the minimax function with depth+1 and isMaximizing set to true to evaluate the opponent's turn, undoes the move, and updates bestScore if the returned score is lower.

After evaluating all possible moves, the function returns bestScore, representing the lowest possible score for the minimizing player.

### bestMove Function

Explanation : 
The function void bestMove() is used to determine the best possible move for the AI player ('O') in the game. The bestMove() function utilizes the minimax() function to evaluate and select the best move for the AI player ('O') by iterating through all possible moves, assigning scores, and choosing the move with the highest score.

The function starts by declaring and initializing variables score, bestScore, x, and y. bestScore is set to a very low value (-1000) to track the highest score found, while x and y will store the coordinates of the best move.

Next, the function iterates through each cell of the game board represented by the arr array using nested loops. It checks if a cell is empty (denoted by '.'). If the cell is empty, it temporarily assigns 'O' to that cell, indicating the AI player's move.

After making the move, the function calls the minimax() function with a depth of 0 and isMaximizing set to false to evaluate the opponent's turn and obtain a score for the current move.

Once the score is obtained, the move is undone by resetting the cell to '.'. The function then compares the obtained score with the current bestScore. If the score is greater than bestScore, it updates bestScore to the new higher score and records the coordinates of the current move in x and y.

After evaluating all possible moves, the function assigns 'O' to the cell with the best move by using the coordinates stored in x and y. This represents the optimal move for the AI player.

### main Function

Explanation : 
The int main() function serves as the central component of the Tic Tac Toe game program. It encompasses the main gameplay logic and controls the flow of the game. The function starts by setting up an infinite while loop, ensuring that the game continues until the player decides to exit.

Inside the loop, the console screen is cleared, and the main menu is displayed using the mainScreen() function. The player is then prompted to choose a level of gameplay, and the game board is initialized by calling the init() function, which sets all the cells to '.'.

The subsequent code handles the chosen level differently. For level 1, a two-player game, the loop allows players to take turns entering their moves until the game reaches a conclusion. The game board is displayed using the gameBoard() function, and the players' moves are validated and placed on the board. After each move, the game result is checked using the result() function, and if the game is over, the corresponding message is displayed.

For level 2, player vs. bot, the loop alternates between the player and the bot. The player's move is obtained through input, while the bot's move is randomly generated using the rand() function. The game result is checked after each move, and if the game is over, the appropriate message is displayed.

Level 3, player vs. AI, follows a similar structure to level 2, but instead of random moves for the AI, the bestMove() function is called to determine the optimal move. Again, the game result is checked, and if the game is over, the corresponding message is displayed.

After the game ends, the player is given the option to play again. If they choose to continue, the loop restarts, and if not, the program terminates. This structure ensures that the game remains interactive and allows for multiple rounds of gameplay.


## Conclusion

## Job Description and Contribution
1. (5025211015) Muhammad Daffa Ashdaqfillah (33,33%)
    - Validation movement, resolving bot random move by time, debugging minimax algorithm.
2. (5025211057) Salsabila Fatma Aripa (33,33%)
    - Layouting terminal, making result checker, debugging minimax algorithm.
3. (5025211254) Yusna Millaturrosyidah (33,33%)
    - Creating game concept, adding turn bot and player movement, debugging minimax algorithm.

![ttd](https://github.com/yusnaaaaa/IF184401_DAA_Q2_5025211015_5025211057_5025211254/assets/91377793/260a46e2-1d05-45d0-a3ad-5a20b81ce726)

