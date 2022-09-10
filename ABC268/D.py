import sys
import itertools

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    S = []
    s_char_num = 0
    for _ in range(N):
        s = input()
        S.append(s)
        s_char_num += len(s)

    t_set = set()
    for _ in range(M):
        t = input()
        t_set.add(t)

    # とりあえず全探索してみる
    bar_max = 16 - s_char_num

    bar_num = []

    def dfs(bar_sum, SS):
        if bar_sum + s_char_num > 16:
            return -1

        if len(bar_num) == N - 1:

            ans = []
            ans.append(SS[0])
            for i, j in zip(bar_num, SS[1:]):
                ans.append("_" * i)
                ans.append(j)

            ans = "".join(ans)
            if len(ans) < 3:
                return -1

            if ans not in t_set:
                return ans

            return -1

        ans = -1
        for i in range(1, bar_max + 1):
            if bar_sum + i + s_char_num > 16:
                break

            bar_num.append(i)

            _ans = dfs(bar_sum=bar_sum + i, SS=SS)
            if _ans != -1:
                ans = _ans
                break
            bar_num.pop()
        return ans

    for SS in itertools.permutations(S):
        ans = dfs(0, SS)
        if ans != -1:
            print(ans)
            return

    print(-1)

    return


if __name__ == "__main__":
    main()
