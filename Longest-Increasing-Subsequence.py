import sys
import bisect
import gc
input = sys.stdin.readline

def lis(a):
  dp = []
  for x in a:
    idx = bisect.bisect_left(dp, x)
    if idx >= len(dp):
      dp.append(x)
    else:
      dp[idx] = x
      
  return len(dp)

n = int(input())
a = list(map(int, input().strip().split(" ")))
gc.collect() # to pass https://dmoj.ca/problem/lis
print(lis(a))
