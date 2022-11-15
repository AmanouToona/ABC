import sys
from collections import deque
from typing import List

sys.setrecursionlimit(10 ** 8)


def toposort(g: List[List[int]]) -> bool:
    # トポロジカルソートの可否を返す
    cnt = [0] * len(g)
    for frm in range(len(g)):
        for to in g[frm]:
            cnt[to] += 1

    q: deque = deque()

    for i, c in enumerate(cnt):
        if c == 0:
            q.append(i)

    while q:
        u = q.pop()
        for v in g[u]:
            cnt[v] -= 1
            if cnt[v] == 0:
                q.append(v)

    for c in cnt:
        if c != 0:
            return False

    return True


def main():
    H, W = map(int, sys.stdin.readline().strip().split())
    A = []
    for _ in range(H):
        A.append(list(map(int, sys.stdin.readline().strip().split())))

    # 行の並べ替え検証
    rows = []
    for A_ in A:
        small = float("inf")
        large = 0

        for a in A_:
            if a == 0:
                continue
            small = min(small, a)
            large = max(large, a)

        if small == float("inf"):
            continue

        rows.append((small, large))

    rows.sort()
    for i in range(len(rows) - 1):
        if rows[i + 1][0] < rows[i][1]:
            print("No")
            return

    # 結節点を作って結合することで計算量を落とす
    # 1 1 1 を 1からの結合先の結節点 に結合して、 次につなげる
    # 例えば 1 が N 個 2 が M この時、全部結合すると NM であるところ、 N + M に落とせる
    g = [[] for _ in range(W)]
    for A_ in A:
        col = [a for a in A_ if a != 0]
        col = list(set(col))
        col.sort()

        num2ord = {num: i for i, num in enumerate(col)}
        offset = len(g)
        g.extend([[] for _ in range(len(num2ord) + 1)])

        for i, a in enumerate(A_):
            if a == 0:
                continue
            g[i].append(offset + num2ord[a] + 1)
            g[offset + num2ord[a]].append(i)

    if toposort(g):
        print("Yes")
    else:
        print("No")

    return


if __name__ == "__main__":
    main()
