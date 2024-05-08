#include <iostream>
#include <string>

int solve(int size, std::string string){
 int numA, numF, moves;
 numA = 0;
 numF = 0;
 moves = 0;

 for (int j = 0; j < size; j++){
   if(string[j] == '('){
     numA += 1;
   }else {
     numF +=1;
     if (numF > numA){
       moves+=1;
       numF-=1;
     }
   }
 }
 std::cout << moves << '\n';
 return 1;
}

int main() {
  int t, size;
  std::string string;
  std::cin >> t;
  for (int i = 0; i < t; i++){
    std::cin >> size;
    std::cin >> string;
    solve(size, string);
  }
  return 0;
}