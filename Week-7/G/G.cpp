#include <iostream>
#include <string>
using namespace std;

int calcularMex(string s2, string s3, int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    if (i < n - 1 and s2[i] != ' ' and s3[i + 1] != ' ' and s2[i + 1] != ' ' and
        s3[i] != ' ') {
      if (s3[i] != s2[i + 1] or s2[i] != s3[i + 1]) {
        result += 2;
        i += 1;
      } else if (s2[i] == '0' and s3[i] == '0') {
        result += 1;
      }
    } else if (s2[i] == '0' and s3[i] == '0') {
      result += 1;
    }
  }
  return result;
}

int main() {
  int t, n, mex, numZeros;
  string s1, s2, s3;
  cin >> t;
  while (t--) {
    mex = 0;
    cin >> n;
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < n; i++) {
      // eliminando colunas onde tem 1 e 0, porque já vale 2
      if (s1[i] != s2[i]) {
        mex += 2;
        s3 += ' ';
      } else {
        // salvando colunas onde não pode fazer isso
        s3 += s1[i];
      }
    }
    mex += calcularMex(s2, s3, n);
    cout << mex << '\n';
    s3 = "";
  }
}