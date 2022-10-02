import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, S = map(int, sys.stdin.readline().strip().split())

    A = []
    B = []
    for _ in range(N):
        a, b = map(int, sys.stdin.readline().strip().split())
        A.append(a)
        B.append(b)

    dp = [[False] * (10001) for _ in range(N + 1)]
    dp[0][0] = True

    for n in range(N):
        for s in range(S + 1):
            if not dp[n][s]:
                continue

            next_a = s + A[n]
            next_b = s + B[n]

            if next_a <= S:
                dp[n + 1][next_a] = True
            if next_b <= S:
                dp[n + 1][next_b] = True

    if not dp[-1][S]:
        print("No")
        return

    # 復元
    print("Yes")
    ans = []

    s = S
    for n in range(N - 1, -1, -1):
        if s - A[n] >= 0 and dp[n][s - A[n]]:
            ans.append("H")
            s -= A[n]
            continue
        else:
            ans.append("T")
            s -= B[n]

    ans.reverse()
    ans = "".join(ans)
    print(ans)

    return


if __name__ == "__main__":
    main()
