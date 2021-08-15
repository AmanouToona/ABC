import sys

# N = int(input())
# A = list(map(int, sys.stdin.readline().strip().split()))

N = int(input())
S = list(map(int, sys.stdin.readline().strip().split()))
T = list(map(int, sys.stdin.readline().strip().split()))


ans = []
t = T[-1] + S[-1]
for i in range(2 * N):
    if t > T[i % N]:
        t = T[i % N]
    ans.append(t)
    t = t + S[i % N]

for i in range(N):
    print(ans[N + i])
