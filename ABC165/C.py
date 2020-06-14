import sys

N, M, Q = map(int, sys.stdin.readline().strip().split())
con = []  # condition
for i in range(Q):
    con.append(list(map(int, sys.stdin.readline().strip().split())))

dig = N + 1  # dig -1 桁の数字を作る
A = [1] * dig
point = 0


def make(min=1, digit=1):
    global point
    for i in range(min, M + 1):
        A[digit] = i
        if digit != dig - 1:
            make(min=i, digit=digit + 1)
        else:
            temp_point = 0
            for c in con:
                if A[c[1]] - A[c[0]] == c[2]:
                    temp_point += c[3]
            point = max(point, temp_point)


for i in range(1, M + 1):
    make(min=i, digit=1)

print(point)
