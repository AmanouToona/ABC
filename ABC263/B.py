import sys


def main():
    N = int(input())
    P = list(map(int, sys.stdin.readline().strip().split()))

    count = 0
    p = N
    while p != 1:
        p = P[p - 2]
        count += 1

    print(count)

    return


if __name__ == "__main__":
    main()
