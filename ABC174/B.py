import sys
import math

N, D = map(int, sys.stdin.readline().strip().split())

count = 0

for _ in range(N):
    x, y = map(int, sys.stdin.readline().strip().split())

    if math.sqrt(x ** 2 + y ** 2) <= D:
        count += 1

print(count)
