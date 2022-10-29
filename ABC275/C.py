import sys
from itertools import combinations, permutations
from math import atan

sys.setrecursionlimit(10 ** 8)

# 凸法的にならべかえる
def cross3(a, b, c):
    return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])


# ps = [(x, y), ...]: ソートされた座標list
def convex_hull(ps):
    qs = []
    N = len(ps)
    for p in ps:
        # 一直線上で高々2点にする場合は ">=" にする
        while len(qs) > 1 and cross3(qs[-1], qs[-2], p) > 0:
            qs.pop()
        qs.append(p)
    t = len(qs)
    for i in range(N - 2, -1, -1):
        p = ps[i]
        while len(qs) > t and cross3(qs[-1], qs[-2], p) > 0:
            qs.pop()
        qs.append(p)
    return qs


def main():
    pown = []
    for h in range(9):
        S = input().strip()
        for w, s in enumerate(S):
            if s == ".":
                continue
            pown.append((h + 1, w + 1))

    ans = 0

    if len(pown) < 4:
        print(ans)
        return

    for pown_ in combinations(pown, 4):
        # 時計回りに並べ替え

        for pown4 in permutations(pown_):

            # 0, 1
            dist2 = (pown4[0][0] - pown4[1][0]) ** 2 + (pown4[0][1] - pown4[1][1]) ** 2

            # 1, 2
            if (pown4[1][0] - pown4[2][0]) ** 2 + (
                pown4[1][1] - pown4[2][1]
            ) ** 2 != dist2:
                continue

            # 2, 3
            if (pown4[2][0] - pown4[3][0]) ** 2 + (
                pown4[2][1] - pown4[3][1]
            ) ** 2 != dist2:
                continue

            # 3, 0
            if (pown4[3][0] - pown4[0][0]) ** 2 + (
                pown4[3][1] - pown4[0][1]
            ) ** 2 != dist2:
                continue

            ans += 1
            break

    print(ans)
    return


if __name__ == "__main__":
    main()
