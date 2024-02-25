import sys
from collections import defaultdict

sys.setrecursionlimit(10**8)


def main():
    S = input().strip()

    cnt = defaultdict(int)

    for s in S:
        cnt[s] += 1

    for i, s in enumerate(S):
        if cnt[s] == 1:
            print(i + 1)
            return

    return


if __name__ == "__main__":
    main()
