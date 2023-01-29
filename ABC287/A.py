import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    cnt_for = 0
    for _ in range(N):
        s = input()
        if s == "For":
            cnt_for += 1

    if cnt_for > N // 2:
        print("Yes")
    else:
        print("No")

    return


if __name__ == "__main__":
    main()
