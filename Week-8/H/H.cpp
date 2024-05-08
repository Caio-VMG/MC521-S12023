#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t, n, aux, spells, par;
  vector<int> v;
  cin >> t;
  while (t--) {
    cin >> n;
    spells = 0;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      v.push_back(aux);
    }
    par = 0;
    for (int j = 0; j < n; j++) {
      if (v[j] == 1) {
        par += 1;
        if (par == 2) {
          spells += 1;
          par = 0;
        }
      }
    }
    if (spells == 0) {
      spells += n;
    } else {
      spells += n - (spells * 2);
    } /* else {
       spells += n - (spells * 2) + 1;
     }*/
    /*cout << "valor j: " << j << '\n';
    if (j > 0 and spells % 2 == 0) {
      spells += n - (j + 1);
    } else if (j > 0 and spells % 2 != 0) {
      spells += n - j;
    } else {
      spells += n;
    }*/

    cout << spells << '\n';
    v.clear();
  }
}