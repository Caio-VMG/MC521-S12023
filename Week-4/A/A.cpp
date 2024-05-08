#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n, aux, tam;
  vector<int> v;
  cin >> t;
  while (t--) {
    cin >> n;
    tam = n;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      v.push_back(aux);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++) {
      if (v[i + 1] - v[i] <= 1) {
        tam--;
      }
    }
    if (tam <= 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    v.clear();
  }
}