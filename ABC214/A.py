import sys

# N = int(input())
# A = list(map(int, sys.stdin.readline().strip().split()))

N = int(input())

if 1 <= N <= 125:
    print(4)
elif N <= 211:
    print(6)
elif N <= 214:
    print(8)

