#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  unsigned t, n, i;
  vector<unsigned> p, dp;
  cin >> t;
  while (t--) {
    cin >> n;
    p.resize(n);
    dp.resize(n);
    for (i = 0; i < n; i++) {
      cin >> p[i];
    }
    dp[0] = 0;
    if (n > 1) {
      dp[1] = (p[0] > p[1]);
    }
    for (i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + (p[i - 1] > p[i]));
    }
    cout << dp[n - 1] << endl;
  }
  return 0;
}