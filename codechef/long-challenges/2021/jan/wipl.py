from sys import stdin, stdout

tests = int(stdin.readline())

while tests > 0:
    tests -= 1

    n, k = map(int, stdin.readline().split())
    heights_map = map(int, stdin.readline().split())
    heights = list(heights_map)

    if n == 1:
        print(-1)
        continue

    heights.sort()
    heights.reverse()

    # list has two boxes taller than needed
    if heights[1] >= k:
        print(2)
        continue
    # list has one tall enough. remove it and compute the other
    # obviously, the one tall enough is first one
    elif heights[0] >= k:
        tracy = 0
        count = 1
        # pick that one and build another
        for i in range(1, len(heights)):
            count += 1
            tracy += heights[i]
            if tracy >= k:
                break

        if tracy >= k:
            print(count)
        else:
            print(-1)
        continue

    # no trivial cases present
    # compute DP to find out minimum needed to reach closest to k
    max_dp = k + heights[0]
    dp = [len(heights) + 1] * max_dp
    temp_dp = [len(heights) + 1] * max_dp
    prev = [-1] * (2 * k)

    heights_len = len(heights)

    for j in range(0, heights_len):
        for i in range(heights[j], max_dp):
            if i == heights[j]:
                dp[i] = 1
                prev[i] = j
            else:
                if (temp_dp[i - heights[j]] + 1) < dp[i]:
                    dp[i] = temp_dp[i - heights[j]] + 1
                    prev[i] = j
        for i in range(1, max_dp):
            temp_dp[i] = dp[i]

    least_count = (heights_len + 1) * 2.0
    count_found = False
    # find the combination with least no. of boxes
    for h in range(k, max_dp):
        if dp[h] < heights_len and dp[h] < (least_count / 2.0):
            # there's a potential combination
            # compute map with used up indices
            cur_height = h
            used_boxes = []
            cur_prev = prev[h]
            while cur_height > 0:
                used_boxes.append(cur_prev)
                cur_height -= heights[cur_prev]
                cur_prev = prev[cur_height]

            # now start in descending order and compute tracy's height
            tracy = 0
            count = 0
            box_idx = 0
            while tracy < k and box_idx < heights_len:
                if used_boxes.__contains__(box_idx):
                    box_idx += 1
                else:
                    count += 1
                    tracy += heights[box_idx]
                    box_idx += 1

            if tracy >= k and least_count > (dp[h] + count):
                count_found = True
                least_count = dp[h] + count
        if count_found:
            break

    if count_found:
        print(least_count)
    else:
        print(-1)
