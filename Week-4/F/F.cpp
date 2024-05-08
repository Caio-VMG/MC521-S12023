#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n, somaPares, somaImpares, aux;
  cin >> t;
  while (t--) {
    somaPares = 0;
    somaImpares = 0;
    cin >> n;
    // condição de existência de solução, n/2 não pode ser impar
    if ((n / 2) % 2 != 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      aux = 2;
      for (int i = 0; i < n / 2; i++) {
        cout << aux << " ";
        somaPares += aux;
        aux += 2;
      }
      aux = 1;
      for (int i = 1; i < n / 2; i++) {
        cout << aux << " ";
        somaImpares += aux;
        aux += 2;
      }
      cout << somaPares - somaImpares << "\n";
    }
  }
}