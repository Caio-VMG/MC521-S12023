#include <cmath>
#include <iostream>
#include <vector>
void solve(int n, int a, int b) {
  int aux = 0;
  float aux2 = a;
  if (a > b) {
    std::cout << "1\n";
  } else {
    aux = ceil(n / aux2);
    std::cout << aux;
    std::cout << "\n";
  }
}
int main() {
  int t, input;
  std::vector<int> n, a, b;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> input;
    n.push_back(input);
    std::cin >> input;
    a.push_back(input);
    std::cin >> input;
    b.push_back(input);
  }

  for (int i = 0; i < t; i++) {
    solve(n.at(i), a.at(i), b.at(i));
  }
  return 0;
}