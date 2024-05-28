#!/usr/bin/python3
import sys

def is_safe(board, row, col, n):
    """Check if it's safe to place a queen at board[row][col]."""
    for i in range(row):
        if board[i] == col:
            return False

    for i in range(row):
        if abs(board[i] - col) == abs(i - row):
            return False

    return True

def solve_nqueens(n, board, row):
    """Use backtracking to find all solutions."""
    if row == n:
        print([[i, board[i]] for i in range(n)])
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row] = col
            solve_nqueens(n, board, row + 1)
            board[row] = -1

def main():
    """Main entry point of the program."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [-1] * n
    solve_nqueens(n, board, 0)

if __name__ == "__main__":
    main()
