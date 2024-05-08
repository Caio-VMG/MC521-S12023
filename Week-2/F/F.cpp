#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  int acertos;
  float soma;
  cin >> s;
  while (s[0] != '*') {
    soma = 0;
    acertos = 0;
    int i = 1;
    while (i < s.size()) {
      while (s[i] != '/') {
        switch (s[i]) {
        case 'W':
          soma += 1.0;
          break;
        case 'H':
          soma += 1.0 / 2.0;
          break;
        case 'Q':
          soma += 1.0 / 4.0;
          break;
        case 'E':
          soma += 1.0 / 8.0;
          break;
        case 'S':
          soma += 1.0 / 16.0;
          break;
        case 'T':
          soma += 1.0 / 32.0;
          break;
        case 'X':
          soma += 1.0 / 64.0;
          break;
        }
        i++;
      }
      if (soma == 1.0) {
        acertos += 1;
      }
      soma = 0;
      i++;
    }

    cout << acertos << '\n';
    cin >> s;
  }
  return 0;
}