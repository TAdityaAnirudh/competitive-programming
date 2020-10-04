tests = int(input())

while tests > 0:
    tests = tests - 1
    inps = [int(x) for x in input().split()]
    n = inps[0]
    x = inps[1]
    p = inps[2]
    k = inps[3]

    arr = [int(x) for x in input().split()]
    arr.sort()
    
    if x == arr[p - 1]:
        print(0)
    else:
        if k > p:
            if arr[p - 1] < x:
                print(-1)
            else:
                count = 0
                i = 0
                while i < p:
                    if arr[i] > x:
                        count = count + 1
                    i = i + 1
                print(count)
        elif k == p:
            if arr[p - 1] > x:
                count = 0
                i = 0
                while i < p:
                    if arr[i] > x:
                        count = count + 1
                    i = i + 1
                print(count)
            else:
                count = 0
                i = len(arr)
                while i >= p:
                    if arr[i - 1] < x:
                        count = count + 1
                    i = i - 1
                print(count)
        else:
            if arr[p - 1] > x:
                print(-1)
            else:
                count = 0
                i = len(arr)
                while i >= p:
                    if arr[i - 1] < x:
                        count = count + 1
                    i = i - 1
                print(count)
