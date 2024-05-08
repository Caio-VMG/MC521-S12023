#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int acabou(string s) {
  if (s[0] == 'D' and s[1] == 'O' and s[2] == 'N' and s[3] == 'E') {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  string s, r;
  int erro;
  getline(cin, s);
  while (!acabou(s)) {
    erro = 0;
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    s.erase(remove(s.begin(), s.end(), ','), s.end());
    s.erase(remove(s.begin(), s.end(), '.'), s.end());
    s.erase(remove(s.begin(), s.end(), '!'), s.end());
    s.erase(remove(s.begin(), s.end(), '?'), s.end());
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    r = s;
    reverse(r.begin(), r.end());
    for (int i = 0; i < r.size() and erro == 0; i++) {
      if (r[i] != s[i]) {
        cout << "Uh oh..\n";
        erro = 1;
      }
    }
    if (!erro) {
      cout << "You won't be eaten!\n";
    }
    getline(cin, s);
  }
  return 0;
}