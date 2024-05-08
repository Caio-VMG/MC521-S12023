#include <iostream>
#include <string>
#include <vector>

int Check(int size, std::string string) {
  int counter = 0;
  if (size == 2 or size % 3 == 2) {
    std::cout << "NO\n";
    return 1;
  } else if (size == 1) {
    std::cout << "YES\n";
    return 1;
  }
  for (int i = 0; i < size; i++) {
    counter += 1;
    if (counter == 3) {
      counter = 0;
      if (string[i] != string[i - 1]) {
        std::cout << "NO\n";
        return 1;
      }
    }
  }
  std::cout << "YES\n";
  return 1;
}

int main() {
  int t, n;
  std::string s;
  std::vector<int> wordSize;
  std::vector<std::string> StringVector;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    wordSize.push_back(n);
    std::cin >> s;
    StringVector.push_back(s);
  }
  for (int i = 0; i < t; i++) {
    Check(wordSize.at(i), StringVector.at(i));
  }
}