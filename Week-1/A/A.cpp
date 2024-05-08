#include <iostream>
#include <vector>

void Candies(int n) {
  int result;
  int aux;
  if (n <= 1) {
    result = 0;
  } else {
    aux = n % 2;
    if (aux == 0) {
      result = (n / 2) - 1;
    } else {
      result = n / 2;
    }
  }
  std::cout << result;
  std::cout << '\n';
}

int main() {
  int t, n;
  std::vector<int> numCandies;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    numCandies.push_back(n);
  }
  for (int i = 0; i < t; i++) {
    Candies(numCandies.at(i));
  }
}