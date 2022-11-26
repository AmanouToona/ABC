import sys

sys.setrecursionlimit(10 ** 8)


def main():
    H, W = map(int, sys.stdin.readline().strip().split())

    S = []
    for _ in range(H):
        S.append(sys.stdin.readline().strip())
    S = [s for s in zip(*S)]

    T = []
    for _ in range(H):
        T.append(sys.stdin.readline().strip())
    T = [t for t in zip(*T)]

    S.sort()
    T.sort()

    if S == T:
        print("Yes")
    else:
        print("No")

    return


if __name__ == "__main__":
    main()
