import sys
import math


def main():
    a, b, d = map(int, sys.stdin.readline().strip().split())

    d = d * math.pi / 180

    x = math.cos(d) * a - math.sin(d) * b
    y = math.sin(d) * a + math.cos(d) * b
    print(x, y)
    return


if __name__ == "__main__":
    main()
