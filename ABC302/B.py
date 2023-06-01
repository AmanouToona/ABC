import sys

sys.setrecursionlimit(10**8)


def main():
    H, W = map(int, sys.stdin.readline().strip().split())
    S = []
    for _ in range(H):
        S.append(sys.stdin.readline().strip())

    for rs in range(H):
        for cs in range(W):
            for dh, dw in zip([0, -1, -1, -1, 0, 1, 1, 1], [1, 1, 0, -1, -1, -1, 0, 1]):
                for i, s in enumerate("snuke"):
                    rn = rs + dh * i
                    cn = cs + dw * i

                    if rn >= H or rn < 0:
                        break
                    if cn >= W or cn < 0:
                        break

                    if S[rn][cn] != s:
                        break

                    if i != 4:
                        continue

                    for i in range(5):
                        print(rs + dh * i + 1, cs + dw * i + 1)
                    return

    return


if __name__ == "__main__":
    main()
