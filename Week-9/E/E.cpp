#include <iostream>
#include <vector>
using namespace std;
int main() {
  int a, b, aux;
  vector<int> v;
  cin >> a >> b;
  v.push_back(b);
  while (a != b and b > a) {
    if (b % 2 == 0 and b / 2 >= a) {
      b = b / 2;
      v.push_back(b);
    } else {
      if (b % 10 != 1 or (b - 1) / 10 < a) {
        cout << "NO";
        return 0;
      }
      b = (b - 1) / 10;
      v.push_back(b);
    }
  }
  cout << "YES\n";
  cout << v.size() << '\n';
  for (int i = v.size() - 1; i > 0; i--) {
    cout << v[i] << ' ';
  }
  cout << v[0];
}