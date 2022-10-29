import sys

sys.setrecursionlimit(10 ** 8)

MOD = 998244353


def calc(row, col, m):
    def calc_(lefttop, row, col):
        ave = (lefttop + (lefttop + 2 * (col - 1) + 2 * m * (row - 1))) // 2
        ave %= MOD

        return ave * row * col

    res = calc_(1, (row + 1) // 2, (col + 1) // 2)
    res += calc_(m + 2, row // 2, col // 2)

    res %= MOD
    return res


def main():
    _, M = map(int, sys.stdin.readline().strip().split())
    Q = int(input())

    for _ in range(Q):
        a, b, c, d = map(int, sys.stdin.readline().strip().split())

        ans = calc(b, d, M)
        ans -= calc(b, c - 1, M)
        ans -= calc(a - 1, d, M)
        ans += calc(a - 1, c - 1, M)

        ans %= MOD
        print(ans)

    return


if __name__ == "__main__":
    main()
