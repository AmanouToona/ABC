import sys
import bisect

sys.setrecursionlimit(10 ** 9)

N, M = map(int, sys.stdin.readline().strip().split())

H = list(map(int, sys.stdin.readline().strip().split()))
W = list(map(int, sys.stdin.readline().strip().split()))


H.sort()

sum_diff = [0] * (N + 1)
for i in range(N - 1):
    sum_diff[i + 2] += sum_diff[i] + H[i + 1] - H[i]

ans = float('inf')

# for w in W:
#     h = H.copy()
#     bi = bisect.insort_left(h, w)

#     in_ans = 0
#     for i in range(N):
#         if i % 2 != 0:
#             continue
#         in_ans += h[i + 1] - h[i]
    
#     ans = min(ans, in_ans)

# print(ans)

for w in W:
    bi = bisect.bisect_left(H, w)
    
    if bi == N:
        in_ans = sum_diff[-2] + abs(w - H[-1])
    else:
        in_ans = abs(w - H[bi - 1]) + (sum_diff[bi] + sum_diff[-1] - sum_diff[bi])
    
    ans = min(ans, in_ans)
print(ans)