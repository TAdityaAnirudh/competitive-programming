tests = int(input())

while tests > 0:
    min_ans = 6
    max_ans = 1
    tests = tests - 1
    size = int(input())
    speed = [int(x) for x in input().split()]

    meetings = []
    for i in range(0, size - 1):
        for j in range(i + 1, size):
            if (speed[i] != speed[j]):
                t = float(i - j) / float(speed[j] - speed[i])
                if t >= 0:
                    meetings.append((t, i, j))

    meetings.sort(key = lambda x: x[0])

    for inf in range(0, size):
        pos = [x for x in range(1, size + 1)]
        infected = [False for x in range(0, size)]
        infected[inf] = True

        for meeting in meetings:
            infected[meeting[1]] = (infected[meeting[1]] or infected[meeting[2]])
            infected[meeting[2]] = infected[meeting[1]]

        count = 0
        for m in range(0, size):
            if infected[m]:
                count = count + 1

        if count < min_ans:
            min_ans = count

        if count > max_ans:
            max_ans = count

    print(str(min_ans) + ' ' + str(max_ans))
