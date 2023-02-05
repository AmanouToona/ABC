import sys
from itertools import product

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    # ワーシャルフロイド
    cnt = [[N] * N for _ in range(N)]
    val = [[0] * N for _ in range(N)]

    for n in range(N):
        S = sys.stdin.readline().strip()

        for i, s in enumerate(S):
            if s == "N":
                continue

            cnt[n][i] = 1
            val[n][i] = A[n] + A[i]

    for k, i, j in product(range(N), repeat=3):
        _cnt = cnt[i][k] + cnt[k][j]
        _val = val[i][k] + val[k][j] - A[k]

        if _cnt < cnt[i][j]:
            cnt[i][j] = _cnt
            val[i][j] = _val
        elif _cnt == cnt[i][j] and val[i][j] < _val:
            val[i][j] = _val

    Q = int(input())
    for _ in range(Q):
        u, v = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1

        if cnt[u][v] == N:
            print("Impossible")
        else:
            print(f"{cnt[u][v]} {val[u][v]}")


if __name__ == "__main__":
    main()
