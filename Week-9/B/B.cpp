#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n;
  vector<float> v;
  cin >> t;
  for (int i = 1; i <= 10000; i++) {
    if (i % 10 != 3 and i % 3 != 0) {
      v.push_back(i);
    }
  }  
  while (t--) {
    cin >> n;
    cout << v[n - 1] << '\n';
  }
}