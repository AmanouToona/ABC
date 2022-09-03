import sys
from collections import defaultdict


def main():
    N = int(input())

    count = defaultdict(int)

    for _ in range(N):
        S = sys.stdin.readline().strip()

        count[S] += 1
        if count[S] == 1:
            print(S)
        else:
            print(f"{S}({count[S] - 1})")

    return


if __name__ == "__main__":
    main()
