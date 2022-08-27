import sys


def main():

    points = []

    for _ in range(4):
        x, y = map(int, sys.stdin.readline().strip().split())
        points.append((x, y))

    vectos = [(0, 1), (1, 2), (2, 3), (3, 0)]

    for i in range(4):
        v1 = vectos[i]
        v2 = vectos[(i + 1) % 4]

        # v1 vector を求める
        x1 = points[v1[0]][0] - points[v1[1]][0]
        y1 = points[v1[0]][1] - points[v1[1]][1]

        # v2 vector を求める
        x2 = points[v2[0]][0] - points[v2[1]][0]
        y2 = points[v2[0]][1] - points[v2[1]][1]

        if x1 * y2 - x2 * y1 <= 0:
            print("No")
            return

    print("Yes")

    return


if __name__ == "__main__":
    main()
