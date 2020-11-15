import sys
import heapq

sys.setrecursionlimit(10 ** 9)
mod = 10 ** 9 + 7

H, W = map(int, sys.stdin.readline().strip().split())

board = []
for h in range(H):
    s = list(str(sys.stdin.readline().strip()))
    board.append(s)

table = [[0] * W for _ in range(H)]
table[0][0] = 1

distance = []
heapq.heapify(distance)
heapq.heappush(distance, (0, 0, 0))  # distance, x, y

fp = [[True] * H for _ in range(W)]

while distance:
    dist, ux, uy = heapq.heappop(distance)
    if fp[ux][uy] is False:
        continue
    fp[ux][uy] = False

    # print(f'\nux: {ux} uy: {uy}')
    # for i in table:
    #     print(i)

    for x in range(1, H):
        vx = ux + x

        if vx >= H:
            break
        if board[vx][uy] == "#":
            break

        table[vx][uy] += table[ux][uy]
        table[vx][uy] %= mod

        heapq.heappush(distance, (dist + x, vx, uy))

    for y in range(1, W):
        vy = uy + y

        if vy >= W:
            break
        if board[ux][vy] == "#":
            break

        table[ux][vy] += table[ux][uy]
        table[ux][vy] %= mod

        heapq.heappush(distance, (dist + y, ux, vy))

    for i in range(1, min(H, W)):
        vx = ux + i
        vy = uy + i

        if vx >= H or vy >= W:
            break
        if board[vx][vy] == "#":
            break

        table[vx][vy] += table[ux][uy]
        table[vx][vy] %= mod

        heapq.heappush(distance, (dist + 2 * i, vx, vy))

    if ux == H - 1 and uy == W - 1:
        break

print(table[H - 1][W - 1])

# for i in table:
#     print(i)
