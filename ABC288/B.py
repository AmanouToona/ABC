import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, K = map(int, sys.stdin.readline().strip().split())
    S = []
    for _ in range(N):
        S.append(sys.stdin.readline().strip())

    S = S[:K]
    S.sort()

    for s in S:
        print(s)

    return


if __name__ == "__main__":
    main()