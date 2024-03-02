import sys
from collections import defaultdict

sys.setrecursionlimit(10**8)


def main():
    N, T = map(int, input().strip().split())

    player = [0] * N
    cnt = defaultdict(int)
    cnt[0] = N
    for _ in range(T):
        a, b = map(int, sys.stdin.readline().strip().split())
        a -= 1

        # 点数変動前の処理
        before = player[a]
        cnt[before] -= 1
        if cnt[before] == 0:
            cnt.pop(before)

        # 点数の変動後の処理
        after = before + b
        player[a] = after
        cnt[after] += 1

        print(len(cnt))

    return


if __name__ == "__main__":
    main()
