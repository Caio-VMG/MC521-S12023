#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t, n, aux, count, foundDupe, pos;
  vector<int> v;
  set<int, greater<int>> s;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    count = 0;
    for (int j = 0; j < n; j++) {
      cin >> aux;
      v.push_back(aux);
    }
    foundDupe = 0;
    pos = v.size() - 1;
    while (!foundDupe and pos >= 0) {
      if (s.count(v.at(pos))) {
        foundDupe = 1;
        count = pos + 1;
      } else {
        s.insert(v.at(pos));
      }
      pos--;
    }
    cout << count << '\n';
    v.clear();
    s.clear();
  }
}