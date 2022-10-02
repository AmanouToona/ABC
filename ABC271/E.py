import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M, K = map(int, sys.stdin.readline().strip().split())

    A = []
    B = []
    C = []
    for _ in range(M):
        a, b, c = map(int, sys.stdin.readline().strip().split())
        A.append(a)
        B.append(b)
        C.append(c)

    E = list(map(int, sys.stdin.readline().strip().split()))

    dp = [float("inf")] * (N + 1)
    dp[1] = 0

    for e in E:
        a = A[e - 1]
        b = B[e - 1]
        c = C[e - 1]

        if dp[a] == float("inf"):
            continue

        dp[b] = min(dp[b], dp[a] + c)

    if dp[N] == float("inf"):
        print(-1)
    else:
        print(dp[N])

    return


if __name__ == "__main__":
    main()
