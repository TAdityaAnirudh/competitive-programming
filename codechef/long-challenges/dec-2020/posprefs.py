from sys import stdin, stdout

t = int(stdin.readline())

while t > 0:
    n, k = map(int, stdin.readline().split())

    if k > (n // 2):
        k = n - k

        # Calculate as many negative values
        sign = 1
        cur_val = 1
        while cur_val <= n:
            stdout.write(str(sign * cur_val) + ' ')
            if k > 0 and sign == -1:
                k -= 1
            sign *= -1
            if k == 0:
                sign = 1
            cur_val += 1
    else:
        sign = -1
        cur_val = 1
        while cur_val <= n:
            stdout.write(str(sign * cur_val) + ' ')
            if k > 0 and sign == 1:
                k -= 1
            sign *= -1
            if k == 0:
                sign = -1
            cur_val += 1
    stdout.write('\n')
    t = t - 1