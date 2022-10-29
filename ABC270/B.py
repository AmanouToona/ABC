import sys

sys.setrecursionlimit(10 ** 8)


def main():
    X, Y, Z = map(int, sys.stdin.readline().strip().split())

    # X が Y より近い
    if 0 < X:
        if Y < 0 or X < Y:
            print(X)
            return
    else:
        if X > Y or 0 < Y:
            print(abs(X))
            return

    # Z が Y より近い
    if 0 < Z:
        if Y < 0 or Z < Y:
            print(Z + abs(X - Z))
            return
    else:
        if Z > Y or 0 < Y:
            print(abs(Z) + abs(X - Z))
            return

    print(-1)
    return


if __name__ == "__main__":
    main()
