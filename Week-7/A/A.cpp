#include <iostream>
#include <set>
using namespace std;

int main() {
  int t, n, busNum;
  set<int> past, actual;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> busNum;
      if (i == 0) {
        past.insert(busNum);
      } else if (past.count(busNum) != 0) {
        actual.insert(busNum);
      }
    }
    if (i != 0) {
      past.clear();
      for (auto a = actual.begin(); a != actual.end(); a++) {
        past.insert(*a);
      }
      actual.clear();
    }
  }
  for (auto a = past.begin(); a != past.end(); a++) {
    cout << *a << " ";
  }
  cout << "\n";
}