import sys

sys.setrecursionlimit(10 ** 8)


def main():
    H, W = map(int, sys.stdin.readline().strip().split())

    A = []
    for _ in range(H):
        A.append(list(map(int, sys.stdin.readline().strip().split())))

    global used, ans
    used = set()
    ans = 0

    def dfs(uh, uw):
        global used, ans
        if uh == H - 1 and uw == W - 1:
            ans += 1
            return

        vh = uh + 1
        vw = uw + 1

        if vh < H:
            if A[vh][uw] not in used:
                used.add(A[vh][uw])
                dfs(vh, uw)

                used.remove(A[vh][uw])

        if vw < W:
            if A[uh][vw] not in used:
                used.add(A[uh][vw])
                dfs(uh, vw)

                used.remove(A[uh][vw])

        return

    used.add(A[0][0])
    dfs(0, 0)
    print(ans)

    return


if __name__ == "__main__":
    main()
