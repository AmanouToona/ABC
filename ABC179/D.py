import sys
sys.setrecursionlimit(10 ** 8)

def main():
    mod = 998244353

    N, K = map(int, sys.stdin.readline().strip().split())

    step = []
    for _ in range(K):
        L, R = map(int, sys.stdin.readline().strip().split())
        step.append((L, R))
    step.sort(reverse=True)

    dp = [False] * (N + 1)
    dp[1] = 1
    dp[0] = 0


    def solve(u):
        if u <= 0:
            return 0

        if dp[u] is not False:
            return dp[u]
        
        dp[u] = 0
        for L, R in step:
            R = min(R, u)
            L = min(L, u)

            if False in dp[(u - R): (u - L + 1)]:    
                for i in range(L, R + 1):
                    dp[u] += solve(u - i)
            else:
                dp[u] = sum(dp[(u - R): (u - L + 1)])

        return dp[u]


    solve(N)

    print(dp[-1] % mod)

if __name__ == '__main__':
    main()
