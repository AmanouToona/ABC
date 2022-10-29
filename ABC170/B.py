import sys

X, Y = map(int, sys.stdin.readline().strip().split())

ans = "No"
for crane in range(X + 1):
    turtle = X - crane

    if Y == crane * 2 + turtle * 4:
        ans = "Yes"
        break

print(ans)
