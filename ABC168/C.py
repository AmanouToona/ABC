import sys
import math


def sin(x):
    return math.sin(math.radians(x))


def cos(x):
    return math.cos(math.radians(x))


A, B, H, M = map(int, sys.stdin.readline().strip().split())

Ay = A * sin(90 - (360 / 12 * H + (360 / 12) / 60 * M))
Ax = A * cos(90 - (360 / 12 * H + (360 / 12) / 60 * M))
By = B * sin(90 - 360 / 60 * M)
Bx = B * cos(90 - 360 / 60 * M)

distance = math.sqrt((Ax - Bx) ** 2 + (Ay - By) ** 2)
print(distance)
