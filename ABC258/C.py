import sys


def main():
    N, Q = map(int, sys.stdin.readline().strip().split())
    S = sys.stdin.readline().strip()

    start_pos = 0
    for _ in range(Q):
        query, x = map(int, sys.stdin.readline().strip().split())

        if query == 1:
            start_pos += x
            start_pos %= N
        else:
            print(S[(x - 1 - start_pos + N) % N])


if __name__ == "__main__":
    main()