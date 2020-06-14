import sys

S = str(input())
T = str(input())

for i, t in enumerate(T[:-1]):
    if S[i] != t:
        print('No')
        break
else:
    print('Yes')
