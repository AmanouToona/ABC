# 191027_ABC 144
"""
# A
import sys
a, b = map(int, sys.stdin.readline().strip().split())
if (1 <= a <= 9) & (1 <= b <= 9):
    print(a * b)
else:
    print(-1)
"""

"""
# B
n = int(input())
ans = 'No'
for i in range(1, 10, 1):
    if (n % i == 0) & (n / i <= 9):
        ans = 'Yes'
        break
print(ans)
"""

"""
# C
n = int(input())
a = 1
b = n
for i in range(1, round(n ** 0.5) + 1):
    if n % i == 0:
        a = i
        b = int(n / a)

print(a + b - 2)
"""

"""
# D
import sys
import math


def main():
    a, b, x = map(int, sys.stdin.readline().strip().split())

    s = x / a
    if s > a * b / 2:
        ans = math.degrees(math.atan(2 * b / a - 2 * s / (a ** 2)))
        print(ans)
    else:
        ans = 90 - math.degrees(math.atan(2 * s / (b ** 2)))
        print(ans)


if __name__ == '__main__':
    main()
"""

"""
# E
import sys
import math
n, k = map(int, sys.stdin.readline().strip().split())
a = list(map(int, sys.stdin.readline().strip().split()))
f = list(map(int, sys.stdin.readline().strip().split()))

a = sorted(a)  # 昇順ソート
f = sorted(f, reverse=True)  # 降順ソート


def team_result(a, f):
    eat = []
    for i, j in zip(a, f):
        eat.append(i * j)
    return(max(eat))


r = team_result(a, f)
l = -1  # l = 0 はあり得るので
while(l + 1 < r):
    mid = (l + r) // 2

    train_cost = 0
    for i, j in zip(a, f):
        train_cost += max(0, math.ceil(i - mid / j))

    if train_cost <= k:
        r = mid
    else:
        l = mid

print(r)
"""
