#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, north, south, east, west, top, bottom, aux;
  string s;
  cin >> n;
  while (n != 0) {
    top = 1;
    north = 2;
    west = 3;
    bottom = 6;
    south = 5;
    east = 4;
    for (int i = 0; i < n; i++) {
      cin >> s;
      switch (s[0]) {
      case 'n':
        aux = top;
        top = south;
        south = bottom;
        bottom = north;
        north = aux;
        break;
      case 's':
        aux = top;
        top = north;
        north = bottom;
        bottom = south;
        south = aux;
        break;
      case 'e':
        aux = top;
        top = west;
        west = bottom;
        bottom = east;
        east = aux;

        break;
      case 'w':
        aux = top;
        top = east;
        east = bottom;
        bottom = west;
        west = aux;
        break;
      }
    }
    cout << top << '\n';
    cin >> n;
  }
  return 0;
}