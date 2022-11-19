import sys

sys.setrecursionlimit(10 ** 8)


def main():
    H, M = map(int, input().strip().split())

    for dh in range(24):
        for dm in range(60):
            m = M + dm
            h = H + dh

            h += m // 60
            m %= 60

            h %= 24

            # 見間違えやすいか検証
            a = h // 10
            b = h % 10
            c = m // 10
            d = m % 10

            qh = a * 10 + c
            qm = b * 10 + d

            if qh < 0 or qh >= 24:
                continue
            if qm < 0 or qm >= 60:
                continue

            print(h, m)
            return

    return


if __name__ == "__main__":
    main()
