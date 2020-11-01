import sys
sys.setrecursionlimit(10 ** 9)

N = int(input())

ans = 0
for n in range(N):
    A, B = map(int, sys.stdin.readline().strip().split())

    B_sum = B * (B + 1) // 2
    A_sum = (A - 1) * A // 2
    
    ans += B_sum - A_sum

print(ans)
