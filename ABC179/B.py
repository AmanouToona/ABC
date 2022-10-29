import sys

N = int(input())

count = 0
ans = "No"
for _ in range(N):
    D1, D2 = map(int, sys.stdin.readline().strip().split())

    if D1 == D2:
        count += 1
    else:
        count = 0

    if count >= 3:
        ans = "Yes"
        break

print(ans)
