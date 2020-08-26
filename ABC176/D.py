import sys
import queue

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
    s = map(str, sys.stdin.readline().strip().split())
    S.append(list(s))


# solve
q = queue.Queue()
q.put((Ch, Cw))
fp = [[float('inf')] * W for _ in range(H)]
while True:
    if q:
        uh, uw = q.get()

        for dh, dw in [(1, 1), (1, -1), (-1, 1), (-1, -1)]:
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
            q.put((dh, dw))
            fp[vh][vw] = fp[uh][uw]

    else:  # 行く場所がないのでワープする
        for h in range(-2, 3):
            for w in range(-2, 3):
                #　到達済みか確認
                if


        pass





