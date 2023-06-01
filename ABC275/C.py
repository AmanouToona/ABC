import sys
from itertools import combinations, permutations
from math import atan

sys.setrecursionlimit(10 ** 8)


def main():
    pown = []
    for h in range(9):
        S = input().strip()
        for w, s in enumerate(S):
            if s == ".":
                continue
            pown.append((h, w))

    ans = 0

    if len(pown) < 4:
        print(ans)
        return

    for pown_ in combinations(pown, 4):
        for pown4 in permutations(pown_):

            # 0, 1
            dist2 = (pown4[0][0] - pown4[1][0]) ** 2 + (pown4[0][1] - pown4[1][1]) ** 2

            # 1, 2
            if (pown4[1][0] - pown4[2][0]) ** 2 + (pown4[1][1] - pown4[2][1]) ** 2 != dist2:
                continue

            # 2, 3
            if (pown4[2][0] - pown4[3][0]) ** 2 + (pown4[2][1] - pown4[3][1]) ** 2 != dist2:
                continue

            # 3, 0
            if (pown4[3][0] - pown4[0][0]) ** 2 + (pown4[3][1] - pown4[0][1]) ** 2 != dist2:
                continue

            ans += 1
            break

    print(ans)
    return


if __name__ == "__main__":
    main()
