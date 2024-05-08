#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t, n, k, direita, esquerda;
  vector<pair<int, int>> v;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int a, b;
    a = 0;
    b = 51;
    for (int i = 0; i < n; i++) {
      cin >> esquerda >> direita;
      if (k >= esquerda and k <= direita) {
        if (a < esquerda) {
          a = esquerda;
        }
        if (b > direita) {
          b = direita;
        }
      }
    }
    if (a == b) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}