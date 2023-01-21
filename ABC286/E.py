import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    # ワーシャルフロイド
    ans = [[[float("inf"), 0]] * N for _ in range(N)]

    for n in range(N):
        S = sys.stdin.readline().strip()

        for i, s in enumerate(S):
            if s == "N":
                continue
            ans[n][i] = [1, A[n] + A[i]]

    for k in range(N):
        for i in range(N):
            for j in range(N):
                cost = ans[i][k][0] + ans[k][j][0]
                gain = ans[i][k][1] + ans[k][j][1] - A[k]

                if cost > ans[i][j][0]:
                    continue

                if cost < ans[i][j][0]:
                    ans[i][j] = [cost, gain]
                else:
                    ans[i][j][1] = max(ans[i][j][1], gain)

    Q = int(input())
    for _ in range(Q):
        U, V = map(int, sys.stdin.readline().strip().split())
        U -= 1
        V -= 1

        cost = ans[U][V][0]
        gain = ans[U][V][1]

        if cost == float("inf"):
            print("Impossible")
        else:
            print(f"{cost} {gain}")

    return


if __name__ == "__main__":
    main()
