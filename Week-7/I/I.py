#Cria uma matriz 2D de tamanho 101x101 para armazenaras combinações
ways = [[0 for _ in range(101)] for _ in range(101)]

#Caso base: quando k = 1, há apenas uma maneira de somar n, que é usando n;
for i in range(101):
  ways[i][1] = 1

#ways[n][k] = sum (x = -)^n(ways[n-x][k-x])
for j in range(1, 100):
  for i in range(101):
    for x in range(101):
      if x + i <= 100:
        ways[i + x][j + 1] += ways[i][j]
        ways[i + x][j + 1] %= 1000000
#loop para ler os valores de n e k e imprimir o resultado até um par de 0
while True:
  #lendo
  n, k = map(int, input().split())
  #Se n e k forem ambos 0, parar o loop
  if n == 0 and k == 0:
    break
  #Caso contrario, imprimir o número de maneiras
  print(ways[n][k])