t = int(input())
for c in range (1, t+1):
  n = int(input())
  s = list(input())
  scarecrows = 0
  i = 0
  while i < n:
    if s[i] == '.':
      scarecrows += 1
      i+= 3
    else:
      i+= 1
  print(f"Case {c}: {scarecrows}")