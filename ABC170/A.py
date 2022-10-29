import sys

x = list(map(int, sys.stdin.readline().strip().split()))
origin = [1, 2, 3, 4, 5]

for i in origin:
    if i not in x:
        ans = i
        print(ans)
        break
