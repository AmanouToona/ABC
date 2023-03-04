import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    cnt = defaultdict(int)
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            if i * j > N:
                break
            cnt[i * j] += 1

    ans = 0
    for i in range(1, N + 1):
        if cnt[i] == 0 or cnt[N - i] == 0:
            continue
        ans += cnt[i] * cnt[N - i]

    print(ans)

    return


if __name__ == "__main__":
    main()
