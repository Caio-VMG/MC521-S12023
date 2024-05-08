#include <iostream>
using namespace std;

int main() {
  int t, a1, a2, a3, a4, res, alice, bob;
  cin >> t;
  while (t--) {
    cin >> a1 >> a2 >> a3 >> a4;
    res = 1;
    if (a1 > 0) {
      res = a1;
      if (a2 <= a3 and
          (a2 or a3 or
           a4)) {      // fico alternando entre a2 e a3 até o menor acabar
        res += a2 * 2; // piadas alternadas contadas
        // confiro se o número de piadas restantes é menor que a mood restante
        if (a1 + 1 > a3 - a2 + a4) {
          // se for eu conto todas as restantes
          res += a3 - a2 + a4;
        } else {
          // senão eu conto até acabar o mood
          res += a1 + 1;
        }
      } else if (a2 or a3 or a4) {
        res += a3 * 2;
        if (a1 + 1 > a2 - a3 + a4) {
          res += a2 - a3 + a4;
        } else {
          res += a1 + 1;
        }
      }
    }
    cout << res << '\n';
  }
}