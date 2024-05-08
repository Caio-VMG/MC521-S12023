#include <iostream>
#include <string>
using namespace std;

int main() {
  int t, n, possivel, pos, cima, baixo, cheguei;
  string top, bottom;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> top;
    cin >> bottom;
    possivel = 1;
    pos = 0;
    cima = 1;
    baixo = 0;
    cheguei = 0;
    while (possivel and !cheguei) {
      if (bottom[pos + 1] == '0' and baixo) {
        pos += 1;
      } else if (bottom[pos + 1] == '0' and cima) {
        pos += 1;
        cima = 0;
        baixo = 1;
      } else if (bottom[pos] == '0' and cima) {
        baixo = 1;
        cima = 0;
      } else if (top[pos + 1] == '0' and cima) {
        pos += 1;
      } else if (top[pos + 1] == '0' and baixo) {
        pos += 1;
        cima = 1;
        baixo = 0;
      } else {
        possivel = 0;
      }
      if (pos == n - 1 and baixo) {
        cheguei = 1;
      }
    }
    if (possivel) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}