# Lê o número de casos de teste
t = int(input())

# Para cada caso de teste
for _ in range(t):
  
  n = int(input())


  a = list(map(int, input().split()))

  if a[0] == 1:
    print(n + 1, end=" ")

    for i in range(1, n):
      print(i, end=" ")

    print(n)
  else:
    flag = False

    for i in range(n - 1):
      if a[i] == 0 and a[i + 1] == 1:
      
        flag = True

        for j in range(1, i + 2):
          print(j, end=" ")

        print(n + 1, end=" ")

        for j in range(i + 2, n):
          print(j, end=" ")

        print(n)
        break

    if not flag:
      for i in range(1, n + 1):
        print(i, end=" ")

      print(n + 1)