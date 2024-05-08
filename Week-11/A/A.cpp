#include <iostream>
using namespace std;

int main() {
  int n, m, count;
  count = 0;
  cin >> m >> n;
  while (m != n) {
    if (n < m) {
      count += m - n;
      n = m;
    } else {
      if (n % 2 != 0) {
        n += 1;
        count += 1;
      }
      if (n != m) {
        n = n / 2;
        count += 1;
      }
    }
  }
  cout << count;
}