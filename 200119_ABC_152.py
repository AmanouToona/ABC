# 200119_ABC_152 atcoder

"""
# A
n, m = map(int, input().split())
if n == m:
    print('yes')

else:
    print('no')
"""

"""
# B
a, b = map(int, input().split())

if a < b:
    ans = str(a) * b
elif a > b:
    ans = str(b) * a
else:
    ans = str(a) * b

print(ans)
"""

"""
# C
n = int(input())
p = [int(i)for i in input().split()]

mnm = p[0]
ans = 0
for i in range(n):
    if p[i] <= mnm:
       ans += 1
       mnm = p[i]

print(ans)
"""

# D
n = int(input())
print(len(str(n)))
print(int(str(n)[0]))

