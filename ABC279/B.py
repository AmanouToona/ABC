import sys

sys.setrecursionlimit(10 ** 8)


def main():
    S = input().strip()
    T = input().strip()

    ok = False
    for left in range(len(S) - len(T) + 1):
        for i, t in enumerate(T):
            if S[left + i] != t:
                break
            if i == len(T) - 1:
                ok = True

    if ok:
        print("Yes")
    else:
        print("No")

    return


if __name__ == "__main__":
    main()
