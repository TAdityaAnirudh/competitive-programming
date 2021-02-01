tests = int(input())

while tests > 0:
    tests = tests - 1
    size = int(input())

    first_line = [int(x) for x in input().split()]
    ans = 0;
    idx = size - 1
    rev = False

    while idx > 0:
        if rev:
            if first_line[idx] == (idx + 1):
                rev = False
                ans = ans + 1
        else:
            if first_line[idx] != (idx + 1):
                rev = True
                ans = ans + 1
        idx = idx - 1

    print(ans)

    i = 2;
    while i <= size:
        input()
        i = i + 1
