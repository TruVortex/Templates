from math import sqrt


def factorize(n):
    ans = []
    for i in range(1, int(sqrt(n)) + 1):
        if n % i == 0:
            ans.append(i)
            if n // i != i:
                ans.append(n // i)
    return ans
