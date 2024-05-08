#include <algorithm>>
#include <iostream>
#include <vector>
using namespace std;

unsigned longest_incresing_subset(const vector<unsigned> &height,
                                  const vector<unsigned> &width) {
  unsigned result = 0, i, j;
  vector<unsigned> lis(height.size());

  lis[0] = width[0];
  for (i = 1; i < height.size(); i++) {
    lis[i] = width[i];
    // relax
    for (j = 0; j < i; j++) {
      if (height[j] < height[i] and lis[i] < lis[j] + width[i]) {
        lis[i] = lis[j] + width[i];
      }
    }
  }
  // achar max
  for (i = 0; i < lis.size(); i++) {
    if (result < lis[i]) {
      result = lis[i];
    }
  }
  return result;
}
int main() {
  unsigned t, c, n, i, lds, lis;
  vector<unsigned> height, width;
  cin >> t;
  for (c = 1; c <= t; c++) {
    cin >> n;
    height.resize(n);
    width.resize(n);

    for (i = 0; i < n; i++) {
      cin >> height[i];
    }

    for (i = 0; i < n; i++) {
      cin >> width[i];
    }

    // calcula maior subsequencia
    lis = longest_incresing_subset(height, width);

    // inverte os vetores de altura e largura para calcular a maior subs
    reverse(height.begin(), height.end());
    reverse(width.begin(), width.end());

    // calcula a maior subsequencia decrescente
    lds = longest_incresing_subset(height, width);

    // imprime
    if (lis >= lds) {
      cout << "Case " << c << ". Increasing (" << lis << "). Decreasing ("
           << lds << ")." << endl;
    } else {
      cout << "Case " << c << ". Decreasing (" << lds << "). Increasing ("
           << lis << ")." << endl;
    }
  }
}