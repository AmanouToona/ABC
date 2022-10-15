import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 8)


def leach_b(frm, to, walls):
    # walls から frm より大きく to 以下の値を返す
    if not walls:
        return to

    # frm より大きい最小のwall の位置
    if walls[-1] < frm:
        return to

    ok = len(walls) - 1
    ng = -1
    while ok - ng > 1:
        mid = (ok + ng) // 2
        if walls[mid] < frm:
            ng = mid
        else:
            ok = mid

    can = walls[ok] - 1

    return min(can, to)


def leach_s(frm, to, walls):
    # walls から frm より小さく to 以上の値を返す
    if not walls:
        return to

    if walls[0] > frm:
        return to

    # frm より 小さく 最大の wall の位置
    ok = 0
    ng = len(walls)
    while ng - ok > 1:
        mid = (ok + ng) // 2
        if walls[mid] > frm:
            ng = mid
        else:
            ok = mid

    can = walls[ok] + 1

    return max(can, to)


def main():
    H, W, rs, cs = map(int, sys.stdin.readline().strip().split())
    rs -= 1
    cs -= 1

    N = int(input())
    wh = defaultdict(list)
    ww = defaultdict(list)
    for _ in range(N):
        r, c = map(int, sys.stdin.readline().strip().split())
        r -= 1
        c -= 1
        wh[c].append(r)
        ww[r].append(c)

    for key in wh.keys():
        wh[key].sort()
    for key in ww.keys():
        ww[key].sort()

    Q = int(input())
    r = rs
    c = cs
    for _ in range(Q):
        d, l = sys.stdin.readline().strip().split()
        l = int(l)

        if d == "L":
            to = leach_s(frm=c, to=max(0, c - l), walls=ww[r])
            c = to
        elif d == "R":
            to = leach_b(frm=c, to=min(W - 1, c + l), walls=ww[r])
            c = to
        elif d == "U":
            to = leach_s(frm=r, to=max(0, r - l), walls=wh[c])
            r = to
        else:
            to = leach_b(frm=r, to=min(H - 1, r + l), walls=wh[c])
            r = to

        print(r + 1, c + 1)

    return


if __name__ == "__main__":
    main()
