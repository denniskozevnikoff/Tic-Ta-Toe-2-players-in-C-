#include <iostream>
#include <vector>

const int SIZE = 3;

char board[SIZE][SIZE];

void initBoard() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

void displayBoard() {
  std::cout << "  0 1 2\n";
  for (int i = 0; i < SIZE; i++) {
    std::cout << i << " ";
    for (int j = 0; j < SIZE; j++) {
      std::cout << board[i][j] << "|";
    }
    std::cout << "\n";
  }
}

bool makeMove(int row, int col, char player) {
  if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
    board[row][col] = player;
    return true;
  } else {
    return false;
  }
}

bool checkWin(char player) {
  // Check rows
  for (int i = 0; i < SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }

  // Check columns
  for (int i = 0; i < SIZE; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}

int main() {
  initBoard();
  displayBoard();

  char player = 'X';
  int row, col;
  while (true) {
    std::cout << "Player " << player << " turn, enter row and col: ";
    std::cin >> row >> col;

    if (!makeMove(row, col, player)) {
      std::cout << "Invalid move!\n";
    } else {
      displayBoard();
      if (checkWin(player)) {
        std::cout << "Player " << player << " wins!\n";
        break;
      }
      player = player == 'X' ? 'O' : 'X';
    }
  }

  return 0;
}
