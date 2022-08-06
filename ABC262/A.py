def main():
    Y = int(input())
    for i in range(4):
        if (Y + i) % 4 == 2:
            print(Y + i)
            return
    return


if __name__ == "__main__":
    main()
