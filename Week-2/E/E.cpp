#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> words, wordslower;
  vector<string> answers;
  string aux;
  int anagram = 0;
  int diff = 0;
  int count1, count2;
  cin >> aux;
  while (aux[0] != '#') {
    words.push_back(aux);
    cin >> aux;
  }

  for (int i = 0; i < words.size(); i++) {
    wordslower.push_back(words[i]);
    transform(wordslower[i].begin(), wordslower[i].end(), wordslower[i].begin(),
              ::tolower);
  }

  for (int i = 0; i < words.size(); i++) {
    for (int j = 0; j < words.size() and !anagram; j++) {
      if (j != i and words[i].length() == words[j].length()) {
        for (int k = 0; k < words[i].length() and diff == 0; k++) {
          count1 = count(wordslower[j].begin(), wordslower[j].end(),
                         wordslower[i][k]);
          count2 = count(wordslower[i].begin(), wordslower[i].end(),
                         wordslower[i][k]);
          if (count1 != count2) {
            diff = 1;
          }
        }
        if (diff == 0) {
          anagram = 1;
        }
        diff = 0;
      }
    }
    if (anagram == 0) {
      answers.push_back(words[i]);
    }
    anagram = 0;
  }
  sort(answers.begin(), answers.end());
  for (int i = 0; i < answers.size(); i++) {
    cout << answers[i] << "\n";
  }
}