import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 8)


def main():
    S = input().strip()

    ans = 0
    for w in range(2, len(S) + 1, 2):
        cnt = defaultdict(int)

        for s in S[:w]:
            cnt[s] += 1
            if cnt[s] % 2 == 0:
                cnt.pop(s)

        if len(cnt) == 0:
            ans += 1

        for l, r in zip(S[:-w], S[w:]):
            cnt[r] += 1

            if l not in cnt.keys():
                cnt[l] = 1
            else:
                cnt[l] -= 1

            if cnt[r] % 2 == 0:
                cnt.pop(r)
            if cnt[l] % 2 == 0:
                cnt.pop(l)

            if len(cnt) == 0:
                ans += 1

    print(ans)

    return


if __name__ == "__main__":
    main()
