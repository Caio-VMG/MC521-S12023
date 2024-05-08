#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t, n, alive, k, l;
  char aux1;
  cin >> t;
  l = 0;
  while (t--) {
    l += 1;
    cin >> n;
    alive = 0;
    vector<char> aux(n, '0');
    vector<vector<char>> v(n, aux);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> aux1;
        v[i][j] = aux1;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (v[i][j] == 'x') {
          alive += 1;
          v[i][j] = '.';
          for (int k = i + 1; k < n and (v[k][j] == '@' or v[k][j] == 'x');
               k++) {
            v[k][j] = '.';
          }
          for (int k = j + 1; k < n and (v[i][k] == '@' or v[i][k] == 'x');
               k++) {
            v[i][k] = '.';
          }
        }
      }
    }
    cout << "Case " << l << ": " << alive << endl;
    v.clear();
  }
}