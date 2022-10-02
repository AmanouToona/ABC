import sys
from collections import deque

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    A = list(set(A))
    A.sort()

    q = deque(A)

    for _ in range(N - len(A)):
        q.append(-1)

    for read in range(1, 10 ** 7):
        if not q:
            print(read - 1)
            return

        if q[0] == read:
            q.popleft()

            if q:
                while q[0] == read:
                    q.popleft()
                    q.append(-1)
            continue

        if len(q) >= 2:
            q.pop()
            q.pop()
            continue

        print(read - 1)
        return


if __name__ == "__main__":
    main()
