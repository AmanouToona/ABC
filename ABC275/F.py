import sys

sys.setrecursionlimit(10 ** 8)


def count_cut(s, n):
    s = list(s)
    s.append(-1)
    s.append(n)
    s.sort()

    cnt = 0
    for i in range(1, len(s)):
        if s[i - 1] + 1 != s[i]:
            cnt += 1

    return cnt


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    ans = [[] for _ in range(M + 1)]

    for i, a in enumerate(A):
        ans[a].append(set([i]))

    for i in range(len(ans)):
        for j in range(i + 1, len(ans)):
            if not ans[i]:
                continue
            if not ans[j]:
                continue

            for a1 in ans[i]:
                for a2 in ans[j]:
                    new_s = a1 | a2
                    if len(new_s) != len(a1) + len(a2):
                        continue

                    sum_a = 0
                    for n in new_s:
                        sum_a += A[n]
                    if sum_a >= len(ans):
                        continue
                    ans[sum_a].append(new_s)

    for a in ans[1:]:
        if not a:
            print(-1)
            continue

        ans = float("inf")
        for a_ in a:
            ans = min(ans, count_cut(a_, N))
        print(ans)

    return


if __name__ == "__main__":
    main()
