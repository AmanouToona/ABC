import sys

N = int(input())

alpha = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
         'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

ans = []
for I in range(12):
    I = 10 - I
    k = sum([26 ** i for i in range(I + 1)])
    # print(f'k : {k}')
    if N >= k:
        # print(f'I: {I}')
        n = N // (26 ** I)
        if n == 27:
            n = 26
        N = N - (26 ** I) * n
        # print(f'n: {n}')
        # print(n)
        ans.append(alpha[int(n - 1)])
    else:
        if ans:
            ans.append('a')
print(''.join(ans))

