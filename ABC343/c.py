import sys

sys.setrecursionlimit(10**8)


def main():
    N = int(input())

    ans = 0
    for i in range(1, 10**6 + 1):
        if i**3 > N:
            break

        a = str(i**3)

        can_ans = True
        for s, t in zip(a, a[::-1]):
            if s != t:
                can_ans = False
                break

        if can_ans:
            ans = a

    print(ans)

    return


if __name__ == "__main__":
    main()
