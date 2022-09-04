import sys

sys.setrecursionlimit(10 ** 8)


def main():
    S = input()

    week = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]

    for i, day in enumerate(week):
        if day != S:
            continue
        print(5 - i)
        return

    return


if __name__ == "__main__":
    main()
