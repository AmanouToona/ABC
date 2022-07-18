from collections import defaultdict


def main():
    S = input()

    s_map = defaultdict(int)

    for s in S:
        s_map[s] += 1

    for key, value in s_map.items():
        if value == 1:
            print(key)
            return

    print(-1)

    return


if __name__ == "__main__":
    main()
