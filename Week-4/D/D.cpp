#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int aux, a, b, c;
  vector<int> v;
  for (int i = 0; i < 4; i++) {
    cin >> aux;
    v.push_back(aux);
  }
  sort(v.begin(), v.end());
  c = v[3] - v[0];
  b = v[3] - v[1];
  a = v[3] - v[2];
  cout << a << " " << b << " " << c << "\n";
}