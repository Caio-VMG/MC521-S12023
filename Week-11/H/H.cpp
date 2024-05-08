#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v;
  vector<int> v2;
  int t, n, aux;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      v.push_back(aux);
      v2.push_back(aux);
    }
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n and n != 1; i++) {
      if (v[i] == v2[i]) {
        if (i + 1 < n) {
          aux = v2[i];
          v2[i] = v2[i + 1];
          v2[i + 1] = aux;
        } else {
          aux = v2[i];
          v2[i] = v2[i - 1];
          v2[i - 1] = aux;
        }
      }
    }
    if (n > 1) {
      for (int i = 0; i < n - 1; i++) {
        cout << v2[i] << " ";
      }
      cout << v2[n - 1] << endl;
    } else {
      cout << "-1\n";
    }
    v.clear();
    v2.clear();
  }
}