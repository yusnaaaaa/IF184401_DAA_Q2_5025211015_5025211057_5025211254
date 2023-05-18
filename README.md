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

## Conclusion

## Job Description and Contribution
1. (5025211015) Muhammad Daffa Ashdaqfillah (33,33%)
    - Validation movement, resolving bot random move by time, debugging minimax algorithm.
2. (5025211057) Salsabila Fatma Aripa (33,33%)
    - Layouting terminal, making result checker, debugging minimax algorithm.
3. (5025211254) Yusna Millaturrosyidah (33,33%)
    - Creating game concept, adding turn bot and player movement, debugging minimax algorithm.

![ttd](https://github.com/yusnaaaaa/IF184401_DAA_Q2_5025211015_5025211057_5025211254/assets/91377793/40b499be-1532-45b8-a257-a82cfd702af8)
