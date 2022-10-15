import sys

sys.setrecursionlimit(10 ** 8)


def main():
    X, K = map(int, sys.stdin.readline().strip().split())

    for k in range(K):
        X //= 10 ** k

        if X % 10 < 5:
            X -= X % 10
        else:
            X += 10 - X % 10

        X *= 10 ** k

    print(X)


if __name__ == "__main__":
    main()
