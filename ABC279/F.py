import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, Q = map(int, sys.stdin.readline().strip().split())

    cnt = N

    for _ in range(Q):
        query = list(map(int, sys.stdin.readline().strip().split()))
        q = query[0]
        X = query[1]

        if q == 3:
            continue
        Y = query[-1]
        if q == 1:
            continue
        if q == 2:
            cnt += 1

    return


if __name__ == "__main__":
    main()
