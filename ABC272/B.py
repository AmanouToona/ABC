import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    pair = dict()
    for i in range(N):
        for j in range(i + 1, N):
            pair[(i, j)] = False

    for _ in range(M):
        kx = list(map(int, sys.stdin.readline().strip().split()))

        for i in range(1, len(kx)):
            for j in range(i + 1, len(kx)):
                pair[(kx[i] - 1, kx[j] - 1)] = True

    for _, val in pair.items():
        if not val:
            print("No")
            return
    print("Yes")

    return


if __name__ == "__main__":
    main()
