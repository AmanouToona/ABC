import sys
from collections import defaultdict

sys.setrecursionlimit(10**8)


def eratosthenes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False

    primes = []
    for i in range(n):
        if not is_prime[i]:
            continue
        primes.append(i)

        j = i * i
        while j <= n:
            is_prime[j] = False
            j += i
    return primes


def make_key(a, primes):
    # 素因数分解
    fuc = defaultdict(int)

    for p in primes:
        while a % p == 0:
            fuc[p] += 1
            a //= p

    fuc[a] += 1

    ans = []
    for k, v in fuc.items():
        if v % 2 == 0:
            continue

        ans.append(k)

    ans.sort()
    ans = tuple(ans)

    return ans


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    rime = eratosthenes(10**3)

    cnt_0 = 0
    cnt = defaultdict(int)

    for a in A:
        if a == 0:
            cnt_0 += 1
            continue
        key = make_key(a, primes=rime)
        cnt[key] += 1

    ans = 0
    ans += cnt_0 * (2 * N - cnt_0 - 1) // 2

    for v in cnt.values():
        if v < 2:
            continue

        ans += v * (v - 1) // 2

    print(ans)

    return


if __name__ == "__main__":
    main()
