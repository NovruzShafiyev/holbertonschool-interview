#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing N
non-attacking queens on an N×N chessboard.
"""
import sys


def solution(board, res, n):
    """Add the solution to the list of solution"""
    tmp = []
    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                tmp.append([i, j])
    res.append(tmp)


def isSafe(board, row, col, n):
    """Determines if a queen can be place at board[row][col]"""
    x = row
    y = col
    while x >= 0:
        if board[x][y] == 1:
            return False
        x -= 1

    x = row
    while x >= 0 and y < n:
        if board[x][y] == 1:
            return False
        x -= 1
        y += 1

    x = row
    y = col
    while x >= 0 and y >= 0:
        if board[x][y] == 1:
            return False
        x -= 1
        y -= 1

    return True


def solve(board, res, row, n):
    """Finds the solutions"""
    if row == n:
        solution(board, res, n)
        return

    for col in range(n):
        if isSafe(board, row, col, n):
            board[row][col] = 1
            solve(board, res, row + 1, n)
            board[row][col] = 0


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    n = sys.argv[1]

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [[0 for _ in range(n)] for _ in range(n)]
    res = []
    solve(board, res, 0, n)

    for s in res:
        print(s)
