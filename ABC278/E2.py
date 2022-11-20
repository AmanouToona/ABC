# 想定法による解法
import sys


def main():
    H, W, N, h, w = map(int, sys.stdin.readline().strip().split())
    A = []
    for _ in range(H):
        A.append(list(map(int, sys.stdin.readline().strip().split())))

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

    for n in range(N + 1):
        for hi in range(H):
            for wi in range(W):
                cusum[hi + 1][wi + 1][n] = cusum[hi][wi + 1] + cusum[hi + 1][wi] - cusum[hi][wi] + A[hi][wi]

    # 前準備
    # [minh, minw, maxh, maxw]
    pos = [[float("inf"), float("inf"), -float("inf"), -float("inf")] for _ in range(N + 1)]
    for hi in range(H):
        for wi in range(W):
            n = A[hi][wi]

            pos[n][0] = min(pos[n][0], hi)
            pos[n][1] = min(pos[n][1], wi)
            pos[n][2] = max(pos[n][2], hi)
            pos[n][3] = max(pos[n][3], wi)

    # 解
    ans = [["0"] * (W - w + 1) for _ in range(H - h + 1)]
    for hi in range(H - h + 1):
        for wi in range(W - w + 1):
            num = 0
            for n in range(N + 1):
                maxh = hi + h - 1
                maxw = wi + w - 1
                minh = hi
                minw = wi

                if pos[n][0] >= minh and pos[n][1] >= minw and pos[n][2] <= maxh and pos[n][3] <= maxw:
                    continue
                num += 1

            ans[hi][wi] = str(num)

    for a in ans:
        print(" ".join(a))

    return


if __name__ == "__main__":
    main()
