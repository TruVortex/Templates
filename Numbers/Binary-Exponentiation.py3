def fast_pow(a, b):
    if b == 0:
        return 1
    temp = fast_pow(a, (b >> 1))
    if b % 2 == 1:
        return temp * temp * a
    else:
        return temp * temp


for i in range(1, 101):
    print(fast_pow(i, 4))
