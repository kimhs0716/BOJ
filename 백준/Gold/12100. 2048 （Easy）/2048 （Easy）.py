# https://www.acmicpc.net/problem/12100
# BOJ 12100 - 2048 (Easy)

import sys
from collections import deque
from itertools import product
from copy import deepcopy
from pprint import pprint
from time import time

input = sys.stdin.readline
N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

def move(board, direction):    
    def rotate(board):
        return [list(x) for x in zip(*board[::-1])]

    def merge(line):
        new_line = [x for x in line if x != 0]
        for i in range(len(new_line) - 1):
            if new_line[i] == new_line[i + 1]:
                new_line[i] *= 2
                new_line[i + 1] = 0
        new_line = [x for x in new_line if x != 0]
        return new_line + [0] * (len(line) - len(new_line))

    def move_left(board):
        new_board = []
        for line in board:
            new_line = merge(line)
            new_board.append(new_line)
        return new_board

    def move_right(board):
        new_board = []
        for line in board:
            new_line = merge(line[::-1])
            new_board.append(new_line[::-1])
        return new_board

    def move_up(board):
        new_board = rotate(board)
        new_board = move_left(new_board)
        new_board = rotate(new_board)
        new_board = rotate(new_board)
        new_board = rotate(new_board)
        return new_board

    def move_down(board):
        new_board = rotate(board)
        new_board = move_right(new_board)
        new_board = rotate(new_board)
        new_board = rotate(new_board)
        new_board = rotate(new_board)
        return new_board

    if direction == 'left':
        return move_left(board)
    elif direction == 'right':
        return move_right(board)
    elif direction == 'up':
        return move_up(board)
    elif direction == 'down':
        return move_down(board)

def get_max(board):
    return max([max(line) for line in board])

def dfs(board, depth):
    if depth == 5:
        return get_max(board)
    max_value = 0
    for direction in ['left', 'right', 'up', 'down']:
        new_board = move(board, direction)
        max_value = max(max_value, dfs(new_board, depth + 1))
    return max_value

print(dfs(board, 0))
