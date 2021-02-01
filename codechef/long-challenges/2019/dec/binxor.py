from typing import List, Dict


class NCR:
    factorials: List[int]
    mod: int
    mod_inverse_cache: Dict = {}

    def __init__(self, max, mod):
        self.max_factorial = max
        self.mod = mod
        self.factorials = [1] * (max + 1)
        temp = 1
        for i in range(1, max + 1):
            temp = (temp * i) % mod
            self.factorials[i] = temp

    def power(self, a, b):
        x = 1
        y = a
        while b > 0:
            if (b % 2) > 0:
                x = (x * y) % self.mod
            y = (y * y) % self.mod
            b = (b // 2)
        return x % self.mod

    def mod_inverse(self, a):
        if a in self.mod_inverse_cache:
            return self.mod_inverse_cache[a]
        self.mod_inverse_cache[a] = self.power(a, self.mod - 2)
        return self.mod_inverse_cache[a]

    def ncr(self, n, r):
        return (self.factorials[n] *
                (self.mod_inverse((self.factorials[r] * self.factorials[n - r]) % self.mod)) % self.mod) % self.mod


tests = int(input())

while tests > 0:
    myncr = NCR(100000, 1000000007)
    tests -= 1
    n = int(input())
    a = input()
    b = input()
    n1 = 0
    n2 = 0
    for c in a:
        if c == '1':
            n1 += 1

    for c in b:
        if c == '1':
            n2 += 1

    if n2 > n1:
        temp_n = n1
        n1 = n2
        n2 = temp_n

    min = n1 - n2

    if n1 + n2 > n:
        max = (2 * n) - (n1 + n2)
    else:
        max = n1 + n2

    ans = 0
    i = min
    while i <= max:
        ans = (ans + myncr.ncr(n, i)) % 1000000007
        i += 2

    print(ans)
