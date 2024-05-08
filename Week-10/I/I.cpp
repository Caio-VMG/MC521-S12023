#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long int t, n, q, aux, l, r, k, sum, resposta;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    sum = 0;
    vector<long long int> v, somasParciais;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      v.push_back(aux);
      sum += aux;
      somasParciais.push_back(sum);
    }

    for (int i = 0; i < q; i++) {
      cin >> l >> r >> k;
      if (l > 1) {
        resposta = sum - (somasParciais[r - 1] - somasParciais[l - 2]) +
                   (k * (l - r + 1));
      } else {
        resposta = sum - somasParciais[r - 1] + (k * (l - r + 1));
      }

      if (resposta % 2 != 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}