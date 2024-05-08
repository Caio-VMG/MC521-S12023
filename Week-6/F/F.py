t = int(input())
for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  ans = 0
  negs = 0
  for i in range(n):
    if a[i] < 0:
      negs += 1
      a[i] = -a[i]
    ans += a[i]
  if negs % 2 == 1:
    ans -= min(a) * 2
  print(ans)