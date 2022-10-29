import sys
import math

D, T, S = map(int, sys.stdin.readline().strip().split())

if D > T * S:
    print("No")
else:
    print("Yes")
