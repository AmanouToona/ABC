import sys

sys.setrecursionlimit(10**8)


def gcd(a, b):
    # euclid の互除法
    if b == 0:
        return a
    return gcd(b, a % b)


def main():
    N, M, K = map(int, sys.stdin.readline().strip().split())

    if N == M:
        return

    ng = 0
    ok = 10**19

    lcm = N * M / gcd(N, M)

    while ok - ng > 1:
        mid = (ok + ng) // 2

        cnt = mid // N + mid // M - mid // lcm * 2

        if cnt >= K:
            ok = mid
        else:
            ng = mid

    print(ok)

    return


if __name__ == "__main__":
    main()

"""
2774247
N=969, M=687, K=6893 q=6877, ok=2774247

"""
