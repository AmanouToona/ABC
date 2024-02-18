import sys

sys.setrecursionlimit(10**8)


def main():
    H, W, _ = map(int, sys.stdin.readline().strip().split())
    T = input()

    S = []
    for _ in range(H):
        S.append(input())

    ans = 0
    for i in range(1, H - 1):
        for j in range(1, W - 1):
            # start is (i, j)

            if S[i][j] == "#":
                continue

            uh = i
            uw = j
            is_ans = True
            for t in T:
                if t == "L":
                    uw -= 1
                elif t == "R":
                    uw += 1
                elif t == "U":
                    uh -= 1
                elif t == "D":
                    uh += 1

                if S[uh][uw] == "#":
                    is_ans = False
                    break

            if is_ans:
                ans += 1

    print(ans)

    return


if __name__ == "__main__":
    main()

"""
6 7 5
LULDR
#######
#...#.#
##...##
#.#...#
#...#.#
#######

-> 2
"""
