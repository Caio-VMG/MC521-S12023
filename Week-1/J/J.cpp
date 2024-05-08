#include <iostream>

void SomaMatriz(int **matriz, int linha, int coluna) {
  int soma = 0;
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      soma += matriz[i][j];
    }
  }
  std::cout << soma << "\n";
}

int Check(int **matriz, int linha, int coluna) {
  for (int i = linha - 2; i > -1; i--) {
    for (int j = coluna - 2; j > -1; j--) {
      if (matriz[i][j] >= matriz[i + 1][j] or
          matriz[i][j] >= matriz[i][j + 1]) {
        std::cout << "-1\n";
        return 0;
      }
    }
  }
  for (int i = linha - 1; i > 0; i--) {
    if (matriz[i][coluna - 1] <= matriz[i - 1][coluna - 1]) {
      std::cout << "-1\n";
      return 0;
    }
  }

  for (int j = coluna - 1; j > 0; j--) {
    if (matriz[linha - 1][j] <= matriz[linha - 1][j - 1]) {
      std::cout << "-1\n";
      return 0;
    }
  }

  SomaMatriz(matriz, linha, coluna);
  return 0;
}

int Solve(int **matriz, int linha, int coluna) {
  int auxLinha1, auxLinha2, auxColuna1, auxColuna2, temZero;
  temZero = 0;
  for (int i = linha - 2; i > 0; i--) {
    for (int j = coluna - 2; j > 0; j--) {
      if (matriz[i][j] == 0) {
        temZero = 1;
        // Menor que estes
        auxLinha1 = matriz[i + 1][j];
        auxColuna1 = matriz[i][j + 1];
        // Maior que estes
        auxLinha2 = matriz[i - 1][j];
        auxColuna2 = matriz[i][j - 1];
        if (auxLinha1 - 1 <= auxLinha2 or auxColuna1 - 1 <= auxColuna2 or
            auxLinha1 - 1 <= auxColuna2 or auxColuna1 - 1 <= auxLinha2) {
          std::cout << "-1\n";
          return 0;
        } else {
          if (auxLinha1 > auxColuna1) {
            matriz[i][j] = auxColuna1 - 1;
          } else {
            matriz[i][j] = auxLinha1 - 1;
          }
        }
      }
    }
  }
  if (temZero) {
    SomaMatriz(matriz, linha, coluna);
  } else {
    Check(matriz, linha, coluna);
  }
  return 0;
}

int main() {
  int linha, coluna, aux;
  std::cin >> linha >> coluna;

  int **matriz = new int *[linha];
  for (int i = 0; i < linha; i++) {
    matriz[i] = new int[coluna];
  }

  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      std::cin >> aux;
      matriz[i][j] = aux;
    }
  }
  Solve(matriz, linha, coluna);
  return 0;
}