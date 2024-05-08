#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n, number, foundi, foundk, done, valori, valork;
  cin >> t;
  t = t;
  while (t--) {
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      cin >> number;
      v.push_back(number);
    }
    done = false;
    for (int j = 0; j < n and !done; j++) {
      foundi = false;
      foundk = false;
      for (int i = 0; i < j and !foundi; i++) {
        if (v[i] < v[j]) {
          foundi = true;
          valori = i + 1;
        }
      }
      for (int k = j + 1; !foundk and k < n; k++) {
        if (v[k] < v[j]) {
          foundk = true;
          valork = k + 1;
        }
      }
      if (foundk and foundi) {
        cout << "YES\n";
        cout << valori << " " << j + 1 << " " << valork << "\n";
        done = true;
      }
    }
    if (!done) {
      cout << "NO\n";
    }
  }
  return 0;
}