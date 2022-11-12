import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    first = set(["H", "D", "C", "S"])
    second = set(list("A23456789TJQK"))
    used = set()

    yes = True
    for _ in range(N):
        S = input().strip()

        if S[0] not in first:
            yes = False
        if S[1] not in second:
            yes = False
        if S in used:
            yes = False
        used.add(S)

    if yes:
        print("Yes")
    else:
        print("No")

    return


if __name__ == "__main__":
    main()
