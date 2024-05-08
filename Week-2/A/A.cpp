#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  float angulo, aux, ang_hora, ang_minutos, posAng;
  int achou;
  while (cin >> angulo) {
    achou = 0;
    int hora, minuto, counter;
    hora = 0;
    minuto = 0;
    counter = 0;
    while (hora != 12 and achou == 0) {
      ang_hora = 6 * hora;
      ang_minutos = 6 * minuto;
      posAng = abs(ang_hora - ang_minutos);
      posAng = min(posAng, 360 - posAng);
      if (posAng == angulo) {
        cout << "Y\n";
        achou = 1;
      }
      minuto++;
      if (minuto == 60) {
        hora++;
        minuto = 0;
      }
    }
    if (!achou) {
      cout << "N\n";
    }
  }

  return 0;
}