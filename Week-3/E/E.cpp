#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t, n;
  cin >> t;
  string aux;
  vector<string> v1, v2, v3;
  set<string> j1, j2, j3;
  int pj1, pj2, pj3, count;
  for (int i = 0; i < t; i++) {
    cin >> n;
    pj1 = 0;
    pj2 = 0;
    pj3 = 0;
    for (int j = 0; j < n; j++) {
      cin >> aux;
      v1.push_back(aux);
      j1.insert(aux);
    }
    for (int j = 0; j < n; j++) {
      cin >> aux;
      v2.push_back(aux);
      j2.insert(aux);
    }
    for (int j = 0; j < n; j++) {
      cin >> aux;
      v3.push_back(aux);
      j3.insert(aux);
    }
    for (int j = 0; j < n; j++) {
      count = 0;
      if (j2.count(v1[j])) {
        count++;
      }
      if (j3.count(v1[j])) {
        count++;
      }
      if (count == 0) {
        pj1 += 3;
      } else if (count == 1) {
        pj1 += 1;
      }
    }
    for (int j = 0; j < n; j++) {
      count = 0;
      if (j1.count(v2[j])) {
        count++;
      }
      if (j3.count(v2[j])) {
        count++;
      }
      if (count == 0) {
        pj2 += 3;
      } else if (count == 1) {
        pj2 += 1;
      }
    }
    for (int j = 0; j < n; j++) {
      count = 0;
      if (j1.count(v3[j])) {
        count++;
      }
      if (j2.count(v3[j])) {
        count++;
      }
      if (count == 0) {
        pj3 += 3;
      } else if (count == 1) {
        pj3 += 1;
      }
    }
    cout << pj1 << " " << pj2 << " " << pj3 << "\n";
    j1.clear();
    j2.clear();
    j3.clear();
    v1.clear();
    v2.clear();
    v3.clear();
  }
}