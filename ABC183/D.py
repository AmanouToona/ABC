import sys

sys.setrecursionlimit(10 ** 9)

N, W = map(int, sys.stdin.readline().strip().split())

cusum = [0] * (2 * 10 ** 5 + 1)

for n in range(N):
    s, t, p = list(map(int, sys.stdin.readline().strip().split()))
    cusum[s] += p
    cusum[t] -= p

if cusum[0] > W:
    print("No")
    sys.exit()

for i in range(len(cusum) - 1):
    cusum[i + 1] += cusum[i]
    if cusum[i + 1] > W:
        print("No")
        sys.exit()


print("Yes")
