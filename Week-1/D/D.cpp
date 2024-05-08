#include <iostream>
#include <vector>

int Waste(std::vector<int> cap, std::vector<int> waste) {
  if (cap.at(0) >= waste.at(0) and cap.at(1) >= waste.at(1) and
      cap.at(2) >= waste.at(2)) {
    cap.at(0) -= waste.at(0);
    cap.at(1) -= waste.at(1);
    cap.at(2) -= waste.at(2);
  } else {
    std::cout << "NO\n";
    return 1;
  }
  if (cap.at(0) > 0 and waste.at(3) > 0) {
    waste.at(3) -= cap.at(0);
    cap.at(0) = 0;
    if (waste.at(3) < 0) {
      waste.at(3) = 0;
    }
  }
  if (cap.at(1) > 0 and waste.at(4) > 0) {
    waste.at(4) -= cap.at(1);
    cap.at(1) = 0;
    if (waste.at(4) < 0) {
      waste.at(4) = 0;
    }
  }
  if (cap.at(2) >= waste.at(3) + waste.at(4)) {
    std::cout << "YES\n";
    return 1;
  } else {
    std::cout << "NO\n";
    return 1;
  }
}

int main() {
  int t, input;
  std::vector<int> capacity;
  std::vector<int> wastes;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 3; j++) {
      std::cin >> input;
      capacity.push_back(input);
    }
    for (int j = 0; j < 5; j++) {
      std::cin >> input;
      wastes.push_back(input);
    }
    Waste(capacity, wastes);
    capacity.clear();
    wastes.clear();
  }
}