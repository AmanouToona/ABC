import sys

sys.setrecursionlimit(10 ** 8)

MOD = 998244353


def calc(x, y, m):
    if y % 2 == 0:
        y_even = y
        y_odd = y - 1
    else:
        y_odd = y
        y_even = y - 1

    y1 = (1 + y_odd) * ((y + 1) // 2) // 2
    y1 %= MOD
    y2 = (2 + y_even) * (y // 2) // 2
    y2 %= MOD

    res = 0

    res += y1 * (x + 1) // 2
    res %= MOD
    res += y2 * (x) // 2
    res %= MOD

    if x % 2 == 0:
        x_even = x
        x_odd = x - 1
    else:
        x_odd = x
        x_even = x - 1

    res += m * (2 + x_even) * ((x + 1) // 2) // 2 * ((y + 1) // 2)
    res %= MOD
    res += m * (1 + x_odd) * (x // 2) // 2 * (y // 2)
    res %= MOD

    return res


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    Q = int(input())

    for _ in range(Q):
        a, b, c, d = map(int, sys.stdin.readline().strip().split())

        ans = calc(b, d, M)
        ans -= calc(b, c - 1, M)
        ans -= calc(a - 1, b, M)
        ans += calc(a - 1, b - 1, M)

        ans %= MOD
        print(ans)

    return


if __name__ == "__main__":
    main()
