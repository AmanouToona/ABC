import sys

sys.setrecursionlimit(10 ** 9)

sx, sy, gx, gy = map(int, sys.stdin.readline().strip().split())

a = (-gy - sy) / (gx - sx)
ans = -sy / a + sx

print(ans)
