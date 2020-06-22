import sys

N = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))

# 各数字の個数を記録するリスト alpha
alpha = [0] * 10 ** 5
for a in A:
    alpha[a - 1] += 1

# beta = [i for i in range(1, 10 ** 5 + 1)]

ans = sum(A)
Q = int(input())
for q in range(Q):
    B, C = map(int, sys.stdin.readline().strip().split())
    # beta[B - 1] = C

    # print(f'alpha : {alpha[B - 1]}')
    # print(f'add: {alpha[B - 1] * (C - B)}')

    ans += alpha[B - 1] * (C - B)

    alpha[C - 1] += alpha[B - 1]
    alpha[B - 1] = 0
    # ans = ans + alpha[B - 1] * (C - B)
    print(ans)
