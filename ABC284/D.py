import sys
import math

sys.setrecursionlimit(10 ** 8)


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
        while j + i <= n:
            j += i
            is_prime[j] = False
    return primes


primes = eratosthenes(3 * 10 ** 6)
primes = set(primes)


def solve():
    N = int(input())

    for prime in primes:
        if N % prime != 0:
            continue

        if (N // prime) % prime == 0:
            p = prime
            q = N // prime // prime
        else:
            q = prime
            p = int(math.sqrt(N / q))

        print(p, q)
        return

    return


def main():
    T = int(input())
    for _ in range(T):
        solve()
    return


if __name__ == "__main__":
    main()
