"""
# A
r = int(input())
print(r ** 2)
"""
"""
# B
n = int(input())
s = input()

if n % 2 != 0:
    print('No')
else:
    ans = True
    for i in range(int(n/2)):
        if s[i] != s[i + int(n/2)]:
            print('No')
            ans = False
            break
    if ans:
        print('Yes')
"""

"""
# C
import itertools
import sys


def dist(A, B):
    return((A[0] - B[0]) ** 2 + (A[1] - B[1]) ** 2) ** 0.5


n = int(input())

position = []
for _ in range(n):
    position.append(list(map(int, sys.stdin.readline().strip().split())))

distance = []
count = 0
for i in itertools.permutations(range(n)):
    for j in range(n - 1):
        distance.append(dist(position[i[j]], position[i[j + 1]]))
    count += 1

# print(count)
# print(distance)
print(sum(distance) / count)
"""

# D
import sys
sys.setrecursionlimit(100000)

hash_no = 10 ** 9 + 7


def move(x, y, X, Y):
    global counter
    if x > X:
        return
    if y > Y:
        return
    if (x == X) and (y == Y):
        counter += 1
        return
    if Y > 2 * (X - x) + y:
        return
    if Y < (X - x) / 2 + y:
        return

    move(x + 1, y + 2, X, Y)
    move(x + 2, y + 1, X, Y)


def main():
    global counter
    x, y = map(int, input().split())
    counter = 0

    if (x + y) % 3 != 0:
        print(0)
    else:
        move(0, 0, x, y)
        print(counter % hash_no)


if __name__ == '__main__':
    main()