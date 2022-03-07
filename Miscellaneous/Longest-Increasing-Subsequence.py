mport sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
def trace(dp, s, t, x, y):
  if x == 0 or y == 0: return ""
  elif s[x - 1] == t[y - 1]: return trace(dp, s, t, x - 1, y - 1) + s[x - 1]
  elif dp[x - 1][y] > dp[x][y - 1]: return trace(dp, s, t, x - 1, y)
  else: return trace(dp, s, t, x, y - 1)
s, t = input().strip(), input().strip()
dp = [[0 for i in range(len(t) + 5)] for i in range(len(s) + 5)]
for i in range(len(s) + 1):
  for j in range(len(t) + 1):
    if i == 0 or j == 0: dp[i][j] = 0
    elif s[i - 1] == t[j - 1]: dp[i][j] = dp[i - 1][j - 1] + 1
    elif s[i - 1] != t[j - 1]: dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
print(trace(dp, s, t, len(s), len(t)))
