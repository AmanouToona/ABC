import sys
import math

H, W = map(int, sys.stdin.readline().strip().split())
cant = list()
for h in range(H):
    A, B = map(int, sys.stdin.readline().strip().split())
    cant.append([A - 1, B - 1])

# dp = [[float('inf')] * W for _ in range(H + 1)]
# for w in range(W):
#     dp[0][w] = 0
#
# # dp 更新
# for i in range()
#
