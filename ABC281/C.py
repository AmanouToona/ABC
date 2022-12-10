import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, T = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    t = T % sum(A)

    tot = 0
    for i, a in enumerate(A):
        if tot + a > t:
            print(i + 1, t - tot)
            return
        tot += a

    return


if __name__ == "__main__":
    main()
