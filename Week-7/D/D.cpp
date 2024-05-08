#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  unsigned n;
  vector<unsigned> dp;
  cin >> s;
  // checar se tem m ou w, se tiver imprime 0 e sai do programa
  for (const char &c : s) {
    if (c == 'w' or c == 'm') {
      cout << 0 << endl;
      return 0;
    }
  }
  n = s.size();
  dp.resize(n + 1);
  dp[0] = dp[1] = 1;
  // comeca do 3 caracter e computa o número de possíveis strings
  for (int i = 2; i <= n; i++) {
    // inicialmente assumo que o número de strings não muda
    dp[i] = dp[i - 1];
    // se o caracter atual é o mesmo que o anterior e esse caracter é n ou u
    // então adiciona o número de strings possíveis de strings que terminam 2
    // char antes
    if (s[i - 1] == s[i - 2] and (s[i - 1] == 'u' or s[i - 1] == 'n')) {
      dp[i] += dp[i - 2];
      dp[i] %= 1000000007;
    }
  }
  cout << dp[n] << endl;
}