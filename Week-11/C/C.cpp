#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, aux;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      v.push_back(aux);
    }
    // pula a torre 1 no sort, pra não perder a posição dela
    sort(v.begin() + 1, v.end());
    for (int i = 1; i < n; i++) {
      if (v[0] < v[i]) {
        aux = v[i] - v[0];
        if (aux % 2 == 0) {
          v[0] += aux / 2;
        } else {
          v[0] += (aux / 2) + 1;
        }
      }
    }
    cout << v[0] << endl;
    v.clear();
  }
}