import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 8)


def main():
    H, W, N, h, w = map(int, sys.stdin.readline().strip().split())
    A = []
    for _ in range(H):
        A.append(list(map(int, sys.stdin.readline().strip().split())))

    cnt = defaultdict(int)
    distincet = set()

    for hi in range(H):
        for wi in range(W):
            a = A[hi][wi]
            cnt[a] += 1
            distincet.add(a)

    # 左上を削る
    for hi in range(h):
        for wi in range(w):
            a = A[hi][wi]
            cnt[a] -= 1
            if cnt[a] == 0:
                distincet.remove(a)

    ans = [[0] * (W - w + 1) for _ in range(H - h + 1)]

    for hi in range(H - h + 1):
        if hi != 0:
            for wi in range(w):
                a = A[hi - 1][wi]
                cnt[a] += 1
                distincet.add(a)

            for wi in range(w):
                a = A[hi + h - 1][wi]
                cnt[a] -= 1
                if cnt[a] == 0:
                    distincet.remove(a)

        cnt_l = cnt.copy()
        distincet_l = distincet.copy()

        for wi in range(W - w + 1):
            if wi != 0:
                for hii in range(hi, hi + h):
                    a = A[hii][wi - 1]
                    cnt_l[a] += 1
                    distincet_l.add(a)

                    a = A[hii][wi + w - 1]
                    cnt_l[a] -= 1
                    if cnt_l[a] == 0:
                        distincet_l.remove(a)

            ans[hi][wi] = len(distincet_l)

    for a in ans:
        a = [str(i) for i in a]
        print(" ".join(a))
    return


if __name__ == "__main__":
    main()
