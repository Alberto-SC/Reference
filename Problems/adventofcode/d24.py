#!/usr/local/bin/python3
import sys
import math
import re
import numpy as np
import functools as ft
import itertools as its

from copy import deepcopy
from collections import defaultdict

if len(sys.argv) < 2:
    INPUT_FILE = "in_24_2"
else:
    INPUT_FILE = sys.argv[1]

data = open(INPUT_FILE).read().rstrip()
data = data.split("\n")

# 0 - white, 1 - black
tiles = defaultdict(lambda: 0)

posSteps = ["e", "se", "sw", "w", "ne", "nw"]


def doStep(posR, posC, direction):
    rowOffset = posR % 2
    if direction == "e":
        posC += 1
    elif direction == "se":
        posR += 1
        posC += 1 - rowOffset
    elif direction == "sw":
        posR += 1
        posC -= rowOffset
    elif direction == "w":
        posC -= 1
    elif direction == "nw":
        posR -= 1
        posC -= rowOffset
    elif direction == "ne":
        posR -= 1
        posC += 1 - rowOffset

    return posR, posC


for path in data:
    steps = []
    while len(path) > 0:
        for hmm in posSteps:
            if path.startswith(hmm):
                steps.append(hmm)
                path = path[len(hmm):]

    posR = 0
    posC = 0

    for step in steps:
        posR, posC = doStep(posR, posC, step)

    tiles[(posR, posC)] = 1 - tiles[(posR, posC)]

# Part 1
# print(sum(t for t in tiles.values()))


def computeDay():
    global tiles
    print(tiles)

    newTiles = tiles.copy()
    poses = newTiles.keys()
    rowP = list(map(lambda p: p[0], poses))
    colP = list(map(lambda p: p[1], poses))

    minR = min(rowP)
    maxR = max(rowP)
    minC = min(colP)
    maxC = max(colP)

    for posR in range(minR - 1, maxR + 2):
        for posC in range(minC - 1, maxC + 2):
            nbrs = map(lambda direction: doStep(
                posR, posC, direction), posSteps)
            bCnt = sum(tiles[nPos] for nPos in nbrs)

            cur = tiles[(posR, posC)]
            if cur == 1 and (bCnt == 0 or bCnt > 2):
                newTiles[(posR, posC)] = 0
            elif cur == 0 and bCnt == 2:
                newTiles[(posR, posC)] = 1

    tiles = newTiles


for _ in range(100):
    print(sum(t for t in tiles.values()))
    computeDay()
print(sum(t for t in tiles.values()))

