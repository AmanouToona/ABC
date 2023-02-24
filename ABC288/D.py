import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, K = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    Q = int(input())
    for _ in range(Q):
        l, r = map(int, sys.stdin.readline().strip().split())

    return


if __name__ == "__main__":
    main()
