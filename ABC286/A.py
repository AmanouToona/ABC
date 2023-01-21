import sys

sys.setrecursionlimit(10 ** 8)


def main():
    _, P, Q, R, S = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    for i, j in enumerate(range(P - 1, Q)):
        A[j], A[R - 1 + i] = A[R - 1 + i], A[j]

    print(*A)

    return


if __name__ == "__main__":
    main()
