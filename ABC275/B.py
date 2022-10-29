import sys

sys.setrecursionlimit(10 ** 8)

MOD = 998244353


def main():
    A, B, C, D, E, F = map(int, sys.stdin.readline().strip().split())

    A %= MOD
    B %= MOD
    C %= MOD
    D %= MOD
    E %= MOD
    F %= MOD

    ans = A * B % MOD * C % MOD - D * E % MOD * F % MOD
    ans += MOD
    ans %= MOD

    print(ans)

    return


if __name__ == "__main__":
    main()
