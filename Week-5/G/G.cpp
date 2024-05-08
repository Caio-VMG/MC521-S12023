#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
  int t, n, m, aux, maior;
  vector<int> red, blue, aux1, aux2;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      red.push_back(aux);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> aux;
      blue.push_back(aux);
    }
    for (int i = 0; i < n; i++){
      if (i == 0){aux1.push_back(red[i]);} else{
        aux1.push_back(aux1[i-1] + red[i]); }
    }
    for (int i = 0; i < m; i++){
      if (i == 0){aux2.push_back(blue[i]);} else{
        aux2.push_back(aux2[i-1] + blue[i]); }
    }
 
    maior = max(0, *max_element(aux1.begin(), aux1.end())) +
            max(0,*max_element(aux2.begin(), aux2.end()));
    cout << maior << "\n";
    blue.clear();
    red.clear();
    aux1.clear();
    aux2.clear();
  }
}