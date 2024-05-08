#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int t, n, count, trade;
  string s;
  cin >> t;
  while (t--) {
    count = 0;
    cin >> n;
    cin >> s;
    trade = 0;
    for (int i = 0; i < n; i++) {
      if (!trade) {
        if (s[i] == '1' and s[i + 1] == '0') {
          count++;
          trade = 1;
        }
      } else {
        if (s[i] == '0' and s[i + 1] == '1') {
          count++;
          trade = 0;
        }
      }
    }
    cout << count << "\n";
  }
}