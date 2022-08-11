K = int(input())

hour = 21

if K >= 60:
    K -= 60
    hour += 1

print(f"{hour:02}:{K:02}")
