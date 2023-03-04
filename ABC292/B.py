import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 8)


def main():
    N, Q = map(int, sys.stdin.readline().strip().split())

    cnt = defaultdict(int)
    for _ in range(Q):
        c, x = map(int, sys.stdin.readline().strip().split())

        if c == 1:
            cnt[x] += 1
        elif c == 2:
            cnt[x] += 2
        else:
            if cnt[x] >= 2:
                print("Yes")
            else:
                print("No")

    return


if __name__ == "__main__":
    main()
