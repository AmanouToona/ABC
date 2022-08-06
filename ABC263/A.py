import sys
from collections import defaultdict


def main():
    cards = list(map(int, sys.stdin.readline().strip().split()))

    count = defaultdict(int)
    for card in cards:
        count[card] += 1

    if len(count) != 2:
        print("No")
        return

    is_fullhouse = False
    for _, value in count.items():
        if value == 2:
            is_fullhouse = True

    if not is_fullhouse:
        print("No")
        return

    print("Yes")

    return


if __name__ == "__main__":
    main()
