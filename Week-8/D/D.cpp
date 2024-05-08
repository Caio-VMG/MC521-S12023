#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, aux, kg_index, cost, chopped, done;
  vector<int> drag, kg;
  cin >> n >> m;
  while (n != 0 and m != 0) {
    for (int i = 0; i < n; i++) {
      cin >> aux;
      drag.push_back(aux);
    }
    for (int i = 0; i < m; i++) {
      cin >> aux;
      kg.push_back(aux);
    }
    sort(kg.begin(), kg.end());
    sort(drag.begin(), drag.end());
    kg_index = 0;
    chopped = 0;
    cost = 0;
    for (int i = 0; i < n and kg_index < m; i++) {
      done = 0;
      for (int j = kg_index; j < m and !done; j++) {
        if (drag[i] <= kg[j]) {
          cost += kg[j];
          kg_index = j + 1;
          chopped += 1;
          done = 1;
        }
      }
    }
    if (chopped == n) {
      cout << cost << '\n';
    } else {
      cout << "Loowater is doomed!\n";
    }
    cin >> n >> m;
    kg.clear();
    drag.clear();
  }
}