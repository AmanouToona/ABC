import sys


def main():
    N, K, D = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    dp = [[-1] * D for _ in range(K + 1)]
    dp[0][0] = 0

    for a in A:
        for i in range(K - 1, -1, -1):
            for j in range(D):
                if dp[i][j] == -1:
                    continue
                dp[i + 1][(j + a) % D] = max(dp[i + 1][(j + a) % D], dp[i][j] + a)

    print(dp[K][0])

    return


if __name__ == "__main__":
    main()
