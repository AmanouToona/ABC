import sys
from itertools import permutations

sys.setrecursionlimit(10**8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    S = []
    for _ in range(N):
        S.append(sys.stdin.readline().strip())

    for i in permutations(range(N)):
        is_ans = True

        for j in range(N - 1):
            Su = S[i[j]]
            Sv = S[i[j + 1]]

            cnt = 0
            for su, sv in zip(Su, Sv):
                if su != sv:
                    cnt += 1

            if cnt > 1:
                is_ans = False

        if is_ans:
            print("Yes")
            return

    print("No")

    return


if __name__ == "__main__":
    main()
