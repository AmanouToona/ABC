def main():
    N = int(input())

    x_max = 998244353

    k = N // x_max

    ans = N - k * x_max
    print(ans)

    return


if __name__ == "__main__":
    main()
