#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> g1, g2;
  int n1, n2, aux, diff1, diff2;
  n1 = 1;
  n2 = 2;
  cin >> n1 >> n2;
  // while para pegar todos casos até receber 0 0
  while (n1 != 0 and n2 != 0) {
    diff1 = 0;
    diff2 = 0;

    // montando primeiro vetor de cartas
    for (int i = 0; i < n1; i++) {
      cin >> aux;
      g1.push_back(aux);
    }
    sort(g1.begin(), g1.end());

    // montando o segundo vetor de cartas
    for (int i = 0; i < n2; i++) {
      cin >> aux;
      g2.push_back(aux);
    }
    sort(g2.begin(), g2.end());

    for (int i = 0; i < n1; i++) {
      // conferindo se a outra pessoa tem essa carta
      if (count(g2.begin(), g2.end(), g1.at(i)) == 0) {
        // se não tiver eu aumento a quantidade de cartas trocáveis
        diff1 += 1;
        // conferindo se a próxima carta é repetida
        while (i + 1 < n1 and g1.at(i) == g1.at(i + 1)) {
          // se for eu já pulo ela
          i++;
        }
      }
    }

    // repete o mesmo processo do loop anterior, mas para o segundo vetor de
    // cartas
    for (int i = 0; i < n2; i++) {
      if (count(g1.begin(), g1.end(), g2.at(i)) == 0) {
        diff2 += 1;
        while (i + 1 < n2 and g2.at(i) == g2.at(i + 1)) {
          i++;
        }
      }
    }

    // limpando vetores
    g1.clear();
    g2.clear();

    // retorno o menor valor entre o número de cartas diferentes
    if (diff1 < diff2) {
      cout << diff1 << "\n";
    } else {
      cout << diff2 << "\n";
    }
    cin >> n1 >> n2;
  }

  return 0;
}