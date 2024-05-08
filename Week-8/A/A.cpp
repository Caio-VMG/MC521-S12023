#include <algorithm>>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t, n, k, aux, maior, limite, soma;
  vector<int> a, b;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      a.push_back(aux);
    }
    for (int i = 0; i < n; i++) {
      cin >> aux;
      b.push_back(aux);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    maior = n - 1;
    limite = k;

    for (int i = 0; i <= n and limite > 0; i++) {
      if (a[i] < b[maior]) {
        aux = a[i];
        a[i] = b[maior];
        b[maior] = aux;
        limite--;
        maior--;
      }
    }
    soma = 0;
    for (int i = 0; i < n; i++) {
      soma += a[i];
    }
    cout << soma << '\n';
    a.clear();
    b.clear();
  }
}