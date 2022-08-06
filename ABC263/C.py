import sys


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    ans = [0] * N

    def dfs(digit):
        if digit == N:
            a = ans.copy()
            a = " ".join([str(i) for i in a])
            print(a)
            return

        if digit != 0:
            start = ans[digit - 1] + 1
        else:
            start = 1

        for i in range(start, M + 1):
            ans[digit] = i
            dfs(digit + 1)

        return

    dfs(0)

    return


if __name__ == "__main__":
    main()
