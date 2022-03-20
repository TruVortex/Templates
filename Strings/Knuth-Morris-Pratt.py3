def kmp(string, pattern):
    i, j, n, m = 0, -1, len(string), len(pattern)
    t = [0] * (m + 1)
    t[0] = -1
    while i < m:
        while j >= 0 and pattern[i] != pattern[j]:
            j = t[j]
        i += 1
        j += 1
        t[i] = j
    i = j = 0
    indices = []
    while i < n:
        while j >= 0 and string[i] != pattern[j]:
            j = t[j]
        i += 1
        j += 1
        if j == m:
            indices.append(i - j)
            j = t[j]
    return indices


ans = kmp('SEVENSEVNSEVENSEVENadASFDAIGDOHO', 'SEVEN')
for index in ans:
    print(index)
