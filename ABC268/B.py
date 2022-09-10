import sys

sys.setrecursionlimit(10 ** 8)


def main():
    S = input()
    T = input()

    if len(T) < len(S):
        print("No")
        return

    for i, s in enumerate(S):
        if T[i] != s:
            print("No")
            return

    print("Yes")

    return


if __name__ == "__main__":
    main()
