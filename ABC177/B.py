import sys
import math

S = list(str(input()))
T = list(str(input()))

if len(S) == len(T):
    ans = len(T)
    change = 0
    for j in range(len(T)):
        if T[j] != S[j]:
            change += 1
    ans = min(ans, change)
else:
    ans = len(T)
    for i in range(len(S) - len(T)):
        change = 0
        for j in range(len(T)):
            # print(f'i {i}, j {j}')
            if T[j] != S[i + j]:
                change += 1

        ans = min(ans, change)

print(ans)
