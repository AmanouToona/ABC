import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, Q = map(int, sys.stdin.readline().strip().split())

    L = []
    for _ in range(N):
        L.append(list(map(int, sys.stdin.readline().strip().split())))

    for _ in range(Q):
        s, t = map(int, sys.stdin.readline().strip().split())
        s -= 1

        print(L[s][t])

    return


if __name__ == "__main__":
    main()
