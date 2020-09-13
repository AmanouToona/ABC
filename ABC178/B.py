import sys
import math

a, b, c, d = map(int, sys.stdin.readline().strip().split())

print(max(a * c, a * d, b * c, b * d))

