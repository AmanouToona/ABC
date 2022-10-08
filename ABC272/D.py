import sys
from collections import deque

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    move = []  # dh, dw
    for i in range(N + 1):
        for j in range(N + 1):
            if i ** 2 + j ** 2 == M:
                move.append((i, j))

    used = [[float("inf")] * N for _ in range(N)]
    used[0][0] = 0
    q = deque()
    q.append((0, 0))

    while q:
        uh, uw = q.popleft()

        for dh_, dw_ in move:
            for i, j in zip([1, 1, -1, -1], [1, -1, 1, -1]):
                dh = dh_ * i
                dw = dw_ * j

                vh = uh + dh
                vw = uw + dw

                if vh < 0 or vh >= N:
                    continue
                if vw < 0 or vw >= N:
                    continue
                if used[vh][vw] != float("inf"):
                    continue

                used[vh][vw] = min(used[vh][vw], used[uh][uw] + 1)
                q.append((vh, vw))

    for h in range(N):
        for w in range(N):
            if used[h][w] == float("inf"):
                used[h][w] = -1

    for ans in used:
        print(" ".join([str(a) for a in ans]))

    return


if __name__ == "__main__":
    main()
