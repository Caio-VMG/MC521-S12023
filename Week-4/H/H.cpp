#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> v1, v2;
  int t, n, aux, count1, count0, ordenado;
  cin >> t;
  while (t--) {
    count0 = count1 = 0;
    ordenado = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      if (i > 0 and v1[i-1] > aux) {
        ordenado = 0;
      }
      v1.push_back(aux);
    }
    for (int i = 0; i < n; i++) {
      cin >> aux;
      if (aux == 1) {
        count1 += 1;
      } else {
        count0 += 1;
      }
      v2.push_back(aux);
    }
    if (ordenado or (count0 > 0 and count1 > 0)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
    v1.clear();
    v2.clear();
  }
}