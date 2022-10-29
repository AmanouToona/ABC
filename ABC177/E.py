import sys
import numpy as np

N = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))

all_c = np.gcd(A[0], A[1])
for i in range(2, len(A)):
    all_c = np.gcd(all_c, A[i])
