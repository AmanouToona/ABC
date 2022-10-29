import sys
import math

mod = 10 ** 9 + 7

N = int(input())

if N <= 1:
    print(0)
    sys.exit()

# ans = comb(N, 2, exact=True) * 2 * (8 ** (N - 2)) + (9 ** N - 8 ** N) * 2
ans = 10 ** N - 8 ** N - (9 ** N - 8 ** N) * 2
print(ans % mod)
