import sys
import queue
import heapq

# input
H, W = map(int, sys.stdin.readline().strip().split())
Ch, Cw = map(int, sys.stdin.readline().strip().split())
Dh, Dw = map(int, sys.stdin.readline().strip().split())
Ch -= 1
Cw -= 1
Dh -= 1
Dw -= 1

S = []
for _ in range(H):
    s = str(input())
    S.append(list(s))


# solve
q = queue.Queue()
q.put((Ch, Cw))
fp = [[float("inf")] * W for _ in range(H)]
fp[Ch][Cw] = 0
while True:
    if q.empty():
        break
    uh, uw = q.get()

    for dh, dw in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        vh = uh + dh
        vw = uw + dw

        # 盤上にいるか確認
        if vh < 0 or vh >= H:
            continue
        if vw < 0 or vw >= W:
            continue

        # 壁の確認
        if S[vh][vw] == "#":
            continue

        # 到達済みか確認
        if fp[vh][vw] <= fp[uh][uw]:
            continue

        # 探索候補地に追加
        q.put((vh, vw))
        fp[vh][vw] = fp[uh][uw]

    for dh in range(-2, 3):
        for dw in range(-2, 3):
            if (dh, dw) in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                continue

            vh = uh + dh
            vw = uw + dw

            # 盤上にいるか確認
            if vh < 0 or vh >= H:
                continue
            if vw < 0 or vw >= W:
                continue

            # 壁の確認
            if S[vh][vw] == "#":
                continue

            # 到達済みか確認
            if fp[vh][vw] <= fp[uh][uw] + 1:
                continue

            # 探索候補地に追加
            q.put((vh, vw))
            fp[vh][vw] = fp[uh][uw] + 1


if fp[Dh][Dw] == float("inf"):
    print(-1)
else:
    print(fp[Dh][Dw])
