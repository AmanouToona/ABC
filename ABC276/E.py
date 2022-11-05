import sys
from collections import deque

sys.setrecursionlimit(10 ** 8)


def main():
    H, W = map(int, sys.stdin.readline().strip().split())
    C = []
    for _ in range(H):
        C.append(input().strip())

    hs = None
    ws = None
    for h in range(H):
        for w in range(W):
            if C[h][w] == "S":
                hs = h
                ws = w

    for h_, w_ in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
        h = hs + h_
        w = ws + w_

        if h < 0 or h >= H:
            continue
        if w < 0 or w >= W:
            continue
        if C[h][w] == "#":
            continue

        dp = [[False] * W for _ in range(H)]
        q = deque()
        q.append((h, w, hs, ws))
        dp[h][w] = True

        while q:
            hu, wu, hp, wp = q.popleft()

            for dh, dw in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                hv = dh + hu
                wv = dw + wu

                if hv < 0 or hv >= H:
                    continue
                if wv < 0 or wv >= W:
                    continue
                if C[hv][wv] == "#":
                    continue
                if dp[hv][wv]:
                    continue
                if hv == hu and wv == wu:
                    continue
                if hv == hp and wv == wp:  # 実質最初だけ
                    continue
                if hv == hs and wv == ws:
                    print("Yes")
                    return
                q.append((hv, wv, hu, wu))
                dp[hv][wv] = True

    print("No")

    return


if __name__ == "__main__":
    main()
