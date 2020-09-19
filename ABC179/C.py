import sys

N = int(input())

ans = 0

for i in range(1, N):
    if i == 1:
        ans += N - 1
        continue

    if i * 2  + 1 <= N:
        ans += (N - 1) // i 
    else:
        ans += N - i
        break

print(ans)
