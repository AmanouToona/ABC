import sys

sys.setrecursionlimit(10**8)


def calc(a2, b2, c2, a3, b3, c3):
    # 重複体積を求める演算
    v1, v2, v3 = (0, 0, 0)

    for a in range(0, 14):
        for b in range(0, 14):
            for c in range(0, 14):
                v = 0
                if (0 <= a <= 6) and (0 <= b <= 6) and (0 <= c <= 6):
                    v += 1
                if (a2 <= a <= a2 + 6) and (b2 <= b <= b2 + 6) and (c2 <= c <= c2 + 6):
                    v += 1
                if (a3 <= a <= a3 + 6) and (b3 <= b <= b3 + 6) and (c3 <= c <= c3 + 6):
                    v += 1

                if v == 1:
                    v1 += 1
                elif v == 2:
                    v2 += 1
                elif v == 3:
                    v3 += 1

    return (v1, v2, v3)


def main():
    v1, v2, v3 = map(int, input().strip().split())

    # 1個目の箱は原点に固定して、残りの箱を <=7 の範囲で動かせばよい

    for a2 in range(0, 8):
        for b2 in range(0, 8):
            for c2 in range(0, 8):
                for a3 in range(0, 8):
                    for b3 in range(0, 8):
                        for c3 in range(0, 8):
                            v1_, v2_, v3_ = calc(a2, b2, c2, a3, b3, c3)
                            # print(v1_, v2_, v3_)
                            if (v1, v2, v3) == (v1_, v2_, v3_):
                                ans = [0, 0, 0, a2, b2, c2, a3, b3, c3]
                                print("Yes")
                                print(" ".join(map(str, ans)))
                                return
    print("No")

    return


if __name__ == "__main__":
    main()
