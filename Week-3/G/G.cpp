#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t, n, aux, aux2, time, f, it;
  f = 0;
  vector<int> inicio, fim;
  vector<pair<int, int>> fila;
  cin >> t;
  for (int i = 0; i < t; i++) {
    if (f) {
      cout << "\n";
    }
    f = 1;
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> aux;
      inicio.push_back(aux);
    }

    for (int j = 0; j < n; j++) {
      cin >> aux;
      fim.push_back(aux);
    }

    for (int j = 0; j < n; j++) {
      fila.push_back(make_pair(inicio[j], fim[j]));
    }

    time = 0;
    it = 0;
    while (it < n) {
      if (time <= fila[it].first) {
        time = fila[it].second;
        cout << fila[it].second - fila[it].first << " ";
      } else {
        aux = fila[it].second - time;
        cout << aux << " ";
        time = time + aux;
      }
      it++;
    }
    fila.clear();
    fim.clear();
    inicio.clear();
  }
}