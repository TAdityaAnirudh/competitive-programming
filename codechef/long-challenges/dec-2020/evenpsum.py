from sys import stdin, stdout

n = int(stdin.readline())

while n > 0:
    a, b = map(int, stdin.readline().split())
    stdout.write(str(((a // 2) * (b // 2)) + ((a - a // 2) * (b - b // 2))) + '\n')
    n = n - 1