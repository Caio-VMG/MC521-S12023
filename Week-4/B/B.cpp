#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

int can(float f, vector<tuple<int, string, float>> eventos) {
  double TankState = f;
  string event;
  double posAtual, numLeaks, gasCons, posEvent, eventEffect;
  posAtual = numLeaks = gasCons = 0;
  for (int i = 0; i < eventos.size(); i++) {
    posEvent = get<0>(eventos[i]);
    event = get<1>(eventos[i]);
    eventEffect = get<2>(eventos[i]);
    TankState -= (posEvent - posAtual) * numLeaks;
    TankState -= (posEvent - posAtual) / 100.00 * gasCons;
    posAtual = posEvent;
    if (TankState <= 0) {
      return 0;
    }
    if (event == "Fuel") {
      gasCons = eventEffect;
    } else if (event == "Leak") {
      numLeaks += 1;
    } else if (event == "Gas") {
      TankState = f;
    } else if (event == "Mechanic") {
      numLeaks = 0;
    }
  }
  return 1;
}

int main() {
  cout << fixed;
  cout << setprecision(3);
  vector<tuple<int, string, float>> eventos;
  int eventPos, okay;
  float eventEffect;
  string eventName, bloat;
  okay = 1;
  int fim = 0;
  while (okay) {
    fim = 0;
    while (!fim) {
      cin >> eventPos >> eventName;
      if (eventName == "Fuel") {
        cin >> bloat;
        cin >> eventEffect;
        eventos.push_back(make_tuple(eventPos, eventName, eventEffect));
      } else if (eventName == "Leak") {
        eventos.push_back(make_tuple(eventPos, eventName, 0));
      } else if (eventName == "Gas") {
        cin >> bloat;
        eventos.push_back(make_tuple(eventPos, eventName, 0));
      } else if (eventName == "Mechanic") {
        eventos.push_back(make_tuple(eventPos, eventName, 0));
      } else {
        eventos.push_back(make_tuple(eventPos, eventName, 0));
        fim = 1;
      }
    }
    double lo = 0.0, hi = MAXFLOAT, mid = 0.0, ans = 0.0;
    while (fabs(hi - lo) > 9e-4) {
      mid = (lo + hi) / 2.0;
      if (can(mid, eventos)) {
        ans = mid;
        hi = mid;
      } else {
        lo = mid;
      }
    }
    cout << ans << "\n";
    eventos.clear();
    cin >> eventPos >> eventName;
    cin >> bloat;
    cin >> eventEffect;
    if (eventEffect == 0) {
      okay = 0;
    } else {
      eventos.push_back(make_tuple(eventPos, eventName, eventEffect));
    }
  }
  return 0;
}