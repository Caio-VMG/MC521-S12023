#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int checkSelfPair(long long num, long long inf, long long sup) {
  if (2 * num >= inf) {
    if (2 * num <= sup) {
      return true;
    }
  }
  return false;
}

int main() {
  long long t, n, l, r, aux, first, count;
  vector<long long> numbers;
  cin >> t;
  first = 1;
  for (int k = 0; k < t; k++) {
    if (!first) {
      cout << "\n";
    }
    first = 0;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      numbers.push_back(aux);
    }
    sort(numbers.begin(), numbers.end());
    count = 0;
    for (int i = 0; i < n - 1; i++) {
      auto sup =
          upper_bound(numbers.begin() + i, numbers.end(), r - numbers[i]);
      auto inf =
          lower_bound(numbers.begin() + i, numbers.end(), l - numbers[i]);
      count += sup - inf;
      if (checkSelfPair(numbers[i], l, r)) {
        count -= 1;
      }
    }
    cout << count;
    numbers.clear();
  }
}