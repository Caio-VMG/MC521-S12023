#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int t, numDig, aux, menorNum;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    reverse(s.begin(), s.end());
    menorNum = 2147483644;
    numDig = s.size();
    for (int ultimo = 0; ultimo < numDig; ultimo++) {
      for (int penultimo = ultimo + 1; penultimo < numDig; penultimo++) {
        aux = (s[penultimo] - '0') * 10 + (s[ultimo] - '0');
        if (aux % 25 == 0) {
          menorNum = min(menorNum, penultimo - 1);
        }
      }
    }
    cout << menorNum << "\n";
  }
}