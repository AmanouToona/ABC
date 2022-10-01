import sys
from collections import deque

sys.setrecursionlimit(10 ** 8)


def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    A.sort()

    queue = deque([])
    for a in A:
        queue.append(a)

    for read in range(1, 10 ** 6):
        if not queue:
            print(read - 1)
            return

        if queue[0] == read:
            queue.popleft()

            if not queue:
                continue

            while queue[0] == read:
                queue.popleft()
                queue.append(-1)

            continue

        if len(queue) < 2:
            print(read - 1)
            return
        queue.pop()
        queue.pop()

    return


if __name__ == "__main__":
    main()
