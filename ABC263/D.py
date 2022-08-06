import sys


def main():
    N, L, R = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    cum = [0]
    for a in A:
        cum.append(cum[-1] + a)

    # cumy = cum[y] - Ry
    cumy = cum.copy()
    for i in range(len(cumy)):
        cumy[i] -= R * i

    # cumy = 累積min (cumy)
    for i in range(len(cumy) - 1, 0, -1):
        cumy[i - 1] = min(cumy[i - 1], cumy[i])

    ans = float("inf")
    for x in range(N + 1):
        _ans = R * N + L * x - cum[x] + cumy[x]
        ans = min(ans, _ans)

    print(ans)

    return


if __name__ == "__main__":
    main()
