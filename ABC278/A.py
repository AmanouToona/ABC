import sys
from collections import deque

sys.setrecursionlimit(10 ** 8)


def main():
    N, K = map(int, sys.stdin.readline().strip().split())
    A = deque(map(int, sys.stdin.readline().strip().split()))

    for _ in range(K):
        A.popleft()
        A.append(0)

    A = list(A)
    ans = [str(i) for i in A]
    print(" ".join(ans))
    return


if __name__ == "__main__":
    main()
