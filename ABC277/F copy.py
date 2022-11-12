import sys

sys.setrecursionlimit(10 ** 8)


def main():
    H, W = map(int, sys.stdin.readline().strip().split())
    A = []
    for _ in range(H):
        A.append(list(map(int, sys.stdin.readline().strip().split())))

    # 行 列 別々に考えることができる

    # 行を入れ替える
    n = []
    for h in range(H):
        ma = 0
        mi = float("inf")
        for a in A[h]:
            if a == 0:
                continue
            if a < mi:
                mi = a
            if ma < a:
                ma = a

        if ma == float("inf"):
            continue

        n.append((mi, ma, h))
    n.sort()

    for i in range(len(n) - 1):
        if n[i][1] > n[i + 1][0]:
            print("No")
            return

    A_ = []
    for _, _, i in n:
        A_.append(A[i])

    # 列を入れ替える
    n = []
    for col in zip(*A):
        ma = 0
        mi = float("inf")
        for a in col:
            if a == 0:
                continue
            if a < mi:
                mi = a
            if ma < a:
                ma = a

        if ma == float("inf"):
            continue

        n.append((mi, ma))

    n.sort(key=lambda x: x[1])
    n.sort()

    for i in range(len(n) - 1):
        if n[i][1] > n[i + 1][1]:
            print("No")
            return

    print("Yes")

    return


if __name__ == "__main__":
    main()
