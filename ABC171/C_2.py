import sys

N = int(input())

alpha = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
         'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

ans = []

for i in range(11):
    N -= 1
    if N < 0:
        break
    ans.append(alpha[N % 26])
    N //= 26

print(''.join(ans[::-1]))
