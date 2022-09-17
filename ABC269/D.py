import sys
from collections import deque

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    board = [[0] * 2001 for _ in range(2001)]

    for _ in range(N):
        x, y = map(int, sys.stdin.readline().strip().split())

        x += 1000
        y += 1000
        board[x][y] = 1

    dh = [-1, -1, 0, 0, 1, 1]
    dw = [-1, 0, -1, 1, 0, 1]

    count = 0
    used = [[False] * 2001 for _ in range(2001)]
    for h in range(2001):
        for w in range(2001):
            if board[h][w] == 0:
                continue

            if used[h][w]:
                continue

            count += 1

            # bfs
            q = deque([])
            q.append((h, w))
            used[h][w] = True

            while q:
                uh, uw = q.popleft()

                for i in range(6):
                    vh = uh + dh[i]
                    vw = uw + dw[i]

                    if vh > 2000 or vh < 0:
                        continue
                    if vw > 2000 or vw < 0:
                        continue

                    if board[vh][vw] == 0:
                        continue
                    if used[vh][vw]:
                        continue

                    q.append((vh, vw))
                    used[vh][vw] = True

    print(count)

    return


if __name__ == "__main__":
    main()
