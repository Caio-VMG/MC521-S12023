#include <iostream>
#include <math.h>

using namespace std;
// Calcula o maior divisor do número n que seja menor do que o limite max (max
// representa o k do exercício)
long long int MaxDivisor(long long int n, long long int max) {
  long long int maior = 0;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i > maior and n / i <= max) {
        maior = n / i;
      } else if (i > maior and i <= max) {
        maior = i;
      }
    }
  }
  return maior;
}

int main() {
  long long int n, t, k, aux;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    // Se n for menor que k, posso simplesmente pegar um pacote de tamanho n
    if (n <= k) {
      cout << 1 << "\n";
    } else {
      // Caso contrário procuro o maior divisor de n que esteja no intervalo 1 a
      // k
      aux = MaxDivisor(n, k);
      if (aux == 0) {
        cout << n << "\n";
      } else {
        cout << n / aux << "\n";
      }
    }
  }
}