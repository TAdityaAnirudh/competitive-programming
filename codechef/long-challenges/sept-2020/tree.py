tests = int(input())

while tests > 0:
    size = int(input())
    if size == 0:
        tests = tests - 1
        continue
    num_set = set()
    for x in input().split():
        if int(x) != 0:
            num_set.add(int(x))
    print(len(num_set))
    tests = tests - 1
