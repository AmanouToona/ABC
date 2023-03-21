import sys

sys.setrecursionlimit(10 ** 8)


def main():
    A, X, M = map(int, sys.stdin.readline().strip().split())

    global cache
    cache = dict()

    def f(x):
        global cache

        if x in cache.keys():
            return cache[x]

        if x == 0:
            return 0

        r = f(x // 2) + (f(x // 2) * pow(A, x // 2, M)) % M

        if x % 2 == 1:
            r = r * A + 1

        r %= M

        cache[x] = r
        return r

    print(f(X))

    return


if __name__ == "__main__":
    main()
