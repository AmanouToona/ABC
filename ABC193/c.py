import sys
import math

N = int(input())

count = 0

searched = set()

for a in range(2, int(math.sqrt(N)) + 1):
    for b in range(2, int(math.log2(N)) + 1):
        ab = pow(a, b)
        if ab > N:
            break

        if ab not in searched:
            count += 1
            searched.add(ab)

print(N - count)
