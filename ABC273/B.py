import sys

sys.setrecursionlimit(10 ** 8)


def main():
    X, K = map(int, sys.stdin.readline().strip().split())

    for i in range(K):
        obj = X % (10 ** (i + 2))

        t_ = 0
        b = 10 ** (i + 1)
        for j in range(11):
            if abs(t_ - obj) >= abs(b * j - obj):
                t_ = b * j

        X //= 10 ** (i + 2)
        X *= 10 ** (i + 2)
        X += t_

    print(X)


if __name__ == "__main__":
    main()
