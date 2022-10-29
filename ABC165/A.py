import sys
import math

K = int(input())
A, B = map(int, sys.stdin.readline().strip().split())

if B >= math.ceil(A / K) * K:
    print("OK")
else:
    print("NG")
