import sys
import heapq

H, W = map(int, sys.stdin.readline().strip().split())
inf = 10 ** 5

table = []
for h in range(H):
    table.append(list(str(sys.stdin.readline().strip())))

warp = {chr(ord("a") + i): [] for i in range(26)}
for h in range(H):
    for w in range(W):
        if table[h][w].isalpha():
            if table[h][w].islower():
                warp[table[h][w]].append((h, w))

            elif table[h][w] == 'S':
                start = (0, h, w)
            else:
                goal = (h, w)

que = [start]
heapq.heapify(que)
dist = [[inf] * W for i in range(H)]
dist[start[1]][start[2]] = 0

while que:
    du, hu, wu = heapq.heappop(que)

    # ゴール確認
    if (hu, wu) == goal:
        print(du)
        sys.exit()

    # テレポート
    if table[hu][wu].isalpha() and table[hu][wu].islower():
        if warp[table[hu][wu]]:
            for hv, wv in warp[table[hu][wu]]:
                if dist[hv][wv] == inf:
                    dist[hv][wv] = du + 1
                    heapq.heappush(que, (du + 1, hv, wv))

    for x, y in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
        hv = hu + x
        wv = wu + y

        if (hv < 0) or (hv >= H) or (wv < 0) or (wv >= W):
            continue

        if table[hv][wv] == "#":
            continue

        if dist[hv][wv] != inf:
            continue

        heapq.heappush(que, (du + 1, hv, wv))
        dist[hv][wv] = du + 1

print(-1)
