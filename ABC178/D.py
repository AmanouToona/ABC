import sys
import math

mod = 10 ** 9 + 7

S = int(input())

if S <= 2:
    print(0)
    sys.exit()

# {x}
ans = 1

N = S - 3
while N >= 3:
    n = N - 2
    ans += (n + 1) * n / 2
    N -= 3
