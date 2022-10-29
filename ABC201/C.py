import sys

S = sys.stdin.readline()

o = 0
x = 0
q = 0

for s in S:
    if s == "o":
        o += 1
    elif s == "x":
        x += 1
    else:
        q += 1

if o > 4 or x == 10:
    print("0")
    sys.exit()

ans = 0
for i in range(10000):
    i = str(i)
    i = i.zfill(4)

    can = True
    for j in range(10):
        if str(j) in i and S[j] == "x":
            can = False
            break

    for j in range(10):
        if str(j) not in i and S[j] == "o":
            can = False
            break

    if can:
        ans += 1

print(ans)
