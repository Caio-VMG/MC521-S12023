#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
int n, k, p1, p2, aux1, first;
float aux2;
string s1, s2;
vector<float> wins, loses;
cout.setf(ios::fixed,ios::floatfield);
cout.precision(3);
first = 1;

while(cin >> n >> k) {
    if(!first){
        cout << "\n";
    }
    for (int i = 0; i < n; i++){
        wins.push_back(0);
        loses.push_back(0);
    }
 aux1 = (k*n*(n-1))/2;
 for (int i = 0; i < aux1; i++){
   cin >> p1 >> s1 >> p2 >> s2;
  if ((s1[0] == 'r' and s2[0] == 's') or (s1[0] == 's' and s2[0] == 'p')
or (s1[0] == 'p' and s2[0] == 'r')) {
  wins[p1-1]+=1;
  loses[p2-1]+=1;
}
   if ((s1[0] == 's' and s2[0] == 'r') or (s1[0] == 'p' and s2[0] == 's')
or (s1[0] == 'r' and s2[0] == 'p')) {
  wins[p2-1]+=1;
  loses[p1-1]+=1;
}
 }
  for (int i = 0; i < n; i++){
    if (loses[i]+wins[i] != 0){
      aux2 = wins[i]/(wins[i]+loses[i]);
      cout << aux2 <<"\n";
    } else {
      cout << "-\n";
    }
    
    
    
  }
wins.clear();
loses.clear();
  first = 0;

 }
}