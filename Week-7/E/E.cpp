#include <iostream>
using namespace std;

int main() {
  int n, v, cost;
  cin >> n >> v;
  if (v >= n - 1) {
    cost = n - 1;
  } else {
    cost = v;
    for (int i = 1; i < n; i++) {
      if (n - i > v) {
        cost += i + 1;
      }
    }
  }
  cout << cost << "\n";
}