#include <algorithm>>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t, n, online;
  vector<int> cedo, tarde;
  cin >> t;
  while (t--) {
    cin >> n;
    online = 0;
    cedo.resize(n);
    tarde.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> cedo[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> tarde[i];
    }
    int PosCedo, Postarde;
    for (PosCedo = n - 1, Postarde = n - 1; PosCedo >= 0 and Postarde >= 0;
         PosCedo--) {
      if (cedo[PosCedo] == tarde[Postarde]) {
        Postarde--;
      } else {
        online += 1;
      }
    }
    cout << online << "\n";
  }
}