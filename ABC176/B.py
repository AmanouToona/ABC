import sys

N = str(input())

n = list(map(int, N))

if sum(n) == 0:
    print('Yes')
elif sum(n) % 9 != 0:
    print('No')
else:
    print('Yes')

