import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    A = [i - 1 for i in A]

    B = [i for i in range(N)]
    pos = {i: i for i in range(N)}

    poss = [pos for _ in range(M + 1)]
    Bs = [B for _ in range(M + 1)]

    for i, a in enumerate(A):
        val1 = B[a]
        val2 = B[a + 1]

        B[a], B[a + 1] = B[a + 1], B[a]
        Bs[i + 1] = B.copy()

        pos = poss[i].copy()
        pos[val1] = a + 1
        pos[val2] = a

        poss[i + 1] = pos

    for i in range(1, M + 1):
        # 操作 i の手前での 0 位置
        pos = poss[i - 1][0]

        # 操作 i を行った時に  上記位置にいる数字
        num = Bs[i][pos]

        # 上記数字が最終的に動く位置
        ans = poss[-1][num]
        print(ans + 1)

    return


if __name__ == "__main__":
    main()
