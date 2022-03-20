def longest_common_substring(a, b):
    dp = [[0 for i in range(len(b))] for j in range(len(a))]
    length = 0
    ans = ''
    for i in range(len(a)):
        for j in range(len(b)):
            if a[i] == b[j]:
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                if dp[i][j] > length:
                    length = dp[i][j]
                    ans = a[i - length + 1:i + 1]
            else:
                dp[i][j] = 0
    return ans


print(longest_common_substring('helloWorldasdjioajfad', 'dasjHelloWorlddasdji'))
print(longest_common_substring('ahelloWorldasdjioajfad', 'dasjHelloWorlddasdji'))
print(longest_common_substring('ahelloWorldasdjioajfad', 'dasjHelloWorld'))
print(longest_common_substring('helloWorld', 'helloWorld'))
