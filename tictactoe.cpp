#include<bits/stdc++.h>
using namespace std;
   const int ROWS = 3;
   const int COLS = 3;
   const char PLAYER_X = 'X';
   const char PLAYER_O = 'O';
   const char EMPTY = ' ';
  void printBoard(const std::vector<std::vector<char>>& board);
  bool isMoveValid(const std::vector<std::vector<char>>& board, int row, int col);
  bool isGameOver(const std::vector<std::vector<char>>& board);
  char checkWinner(const std::vector<std::vector<char>>& board);
  int evaluateBoard(const std::vector<std::vector<char>>& board);
  int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizing);
  void makeComputerMove(std::vector<std::vector<char>>& board);

     int main() {
     std::vector<std::vector<char>> board(ROWS, std::vector<char>(COLS, EMPTY));
     int currentPlayer = 0; 
     int moves = 0;

        while (!isGameOver(board) && moves < ROWS * COLS) {
           printBoard(board);

        if (currentPlayer == 0) {
            int row, col;
            std::cout << "Player X's turn. Enter row (0-2) and column (0-2): ";
            std::cin >> row >> col;

            if (isMoveValid(board, row, col)) {
                board[row][col] = PLAYER_X;
                currentPlayer = 1;
                moves++;
            } else {
                std::cout << "Invalid move. Try again." << std::endl;
            }
        } else {
            makeComputerMove(board);
            currentPlayer = 0;
            moves++;
        }
    }

    printBoard(board);

    char winner = checkWinner(board);
    if (winner == PLAYER_X) {
        std::cout << "Player X wins!" << std::endl;
    } else if (winner == PLAYER_O) {
        std::cout << "Player O wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }

    return 0;
}

void printBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "Tic-Tac-Toe Board:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << board[i][j];
            if (j < COLS - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < ROWS - 1) std::cout << "---------" << std::endl;
    }
}

bool isMoveValid(const std::vector<std::vector<char>>& board, int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == EMPTY);
}

bool isGameOver(const std::vector<std::vector<char>>& board) {
    return (checkWinner(board) != EMPTY || std::count(board.begin(), board.end(), std::vector<char>(COLS, EMPTY)) == 0);
}

char checkWinner(const std::vector<std::vector<char>>& board) {
     for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
            return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return board[0][2];
    return EMPTY;
}

int evaluateBoard(const std::vector<std::vector<char>>& board) {
    char winner = checkWinner(board);
    if (winner == PLAYER_X) {
        return -1;
    } else if (winner == PLAYER_O) {
        return 1;
    } else {
        return 0;
    }
}

int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizing) {
    int score = evaluateBoard(board);
     if (score == 1 || score == -1) {
        return score;
    }

    if (std::count(board.begin(), board.end(), std::vector<char>(COLS, EMPTY)) == 0) {
        return 0; // It's a draw
    }

    if (isMaximizing) {
        int maxScore = std::numeric_limits<int>::min();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    maxScore = std::max(maxScore, minimax(board, depth + 1, false));
                    board[i][j] = EMPTY;
                }
            }
        }
        return maxScore;
    } else {
        int minScore = std::numeric_limits<int>::max();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X;
                    minScore = std::min(minScore, minimax(board, depth + 1, true));
                    board[i][j] = EMPTY;
                }
            }
        }
        return minScore;
    }
}

void makeComputerMove(std::vector<std::vector<char>>& board) {
     int bestMove = std::numeric_limits<int>::min();
    int bestRow = -1, bestCol = -1;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_O;
                int moveScore = minimax(board, 0, false);
                board[i][j] = EMPTY;

                if (moveScore > bestMove) {
                    bestMove = moveScore;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }

    board[bestRow][bestCol] = PLAYER_O;
}
