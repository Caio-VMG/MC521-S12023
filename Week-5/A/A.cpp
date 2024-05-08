#include <algorithm>>
#include <iostream>
#include <vector>
using namespace std;
 
int min(int a, int b, int c) {
  if (a <= b and a <= c) {
    return a;
  } else if (b <= a and b <= c) {
    return b;
  } else {
    return c;
  }
}
 
int main() {
  int t, n, aux, minPos, maxPos, steps, maior, menor, res;
  vector<int> v;
  cin >> t;
  while (t--) {
    steps = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      v.push_back(aux);
    }
    minPos = min_element(v.begin(), v.end()) - v.begin() + 1;
    maxPos = max_element(v.begin(), v.end()) - v.begin() + 1;
    if (maxPos > minPos) {
      maior = maxPos;
      menor = minPos;
    } else {
      maior = minPos;
      menor = maxPos;
    }
    res = min(n - menor + 1, maior, n - maior + menor + 1);
    v.clear();
    cout << res << "\n";
  }
}