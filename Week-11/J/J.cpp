#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int r1, c1, r2, c2, king, bishop, rook;
  cin >> r1 >> c1 >> r2 >> c2;
  // primeiro o rei;
  int a = abs(r1 - r2);
  int b = abs(c1 - c2);
  king = max(a, b);
  // agora a torre
  // vendo se tá na msm linha ou coluna

  if (r1 == r2 or c1 == c2) {
    rook = 1;
  } else {
    rook = 2;
  }
  // Agora o bispo
  // vendo se tá na mesma diagonal
  int msmDiag = 0;
  for (int i = 0; i < 9; i++) {
    if ((c1 + i == c2 and r1 + i == r2) or (c1 - i == c2 and r1 - i == r2) or
        (c1 - i == c2 and r1 + i == r2) or (c1 + i == c2 and r1 - i == r2)) {
      msmDiag = 1;
    }
  }
  if (msmDiag) {
    bishop = 1;
  } else {
    if ((r1 + c1) % 2 != (r2 + c2) % 2) {
      bishop = 0;
    } else {
      bishop = 2;
    }
  }
  cout << rook << " " << bishop << " " << king << endl;
}