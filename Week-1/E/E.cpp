#include <iostream>
#include <vector>

int Solve(int n) {
  int counter, aux;
  counter = 0;
  while (n != 1) {
    while (n >= 6 and n % 6 == 0) {
      n = n / 6;
      counter += 1;
    }
    if (n != 1) {
      n = n * 2;
      counter += 1;
      if (n % 3 != 0) {
        std::cout << "-1";
        std::cout << "\n";
        return 0;
      }
    }
  }
  std::cout << counter;
  std::cout << "\n";
  return 0;
}

int main() {
  int t, n;
  std::vector<int> nums;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    nums.push_back(n);
  }
  for (int i = 0; i < t; i++) {
    Solve(nums.at(i));
  }
}