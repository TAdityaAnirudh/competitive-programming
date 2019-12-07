tests = int(raw_input())

while tests > 0:
    tests -= 1;
    int(raw_input())
    input = [int(x) for x in raw_input().split()]
    twos = 0;
    zeros = 0;
    for inp in input:
        if inp == 2:
            twos += 1;
        elif inp == 0:
            zeros += 1;
    print(((twos)*(twos-1)/2) + (((zeros)*(zeros-1))/2))
