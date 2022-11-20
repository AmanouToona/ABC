# imos 法による解法
import sys
from collections import defaultdict


def main():
    H, W, N, h, w = map(int, sys.stdin.readline().strip().split())
    A = []
    for _ in range(H):
        A.append(list(map(int, sys.stdin.readline().strip().split())))

    cnt = defaultdict(int)
    for Ai in A:
        for a in Ai:
            cnt[a] += 1

    # cusum[h][w][a]
    cusum = [[[0] * (N + 1) for _ in range(W + 1)] for _ in range(H + 1)]

    for hi in range(H):
        for wi in range(W):
            cusum[hi + 1][wi + 1][A[hi][wi]] += 1

    # O(300 ** 3)
    for n in range(N + 1):
        for hi in range(H + 1):
            for wi in range(W):
                cusum[hi][wi + 1][n] += cusum[hi][wi][n]

        for hi in range(H):
            for wi in range(W + 1):
                cusum[hi + 1][wi][n] += cusum[hi][wi][n]

    # solve
    ans = [[0] * (W - w + 1) for _ in range(H - h + 1)]
    for hi in range(H - h + 1):
        for wi in range(W - w + 1):
            nums = 0
            for n in range(N + 1):
                # 塗りつぶされた個数
                draw = cusum[hi + h][wi + w][n] - cusum[hi][wi + w][n] - cusum[hi + h][wi][n] + cusum[hi][wi][n]
                rest = cnt[n] - draw

                if rest != 0:
                    nums += 1
            ans[hi][wi] = str(nums)

    for a in ans:
        print(" ".join(a))

    return


if __name__ == "__main__":
    main()
