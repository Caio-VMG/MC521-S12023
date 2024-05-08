#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <sstream>

using namespace std;

int main() {
  unsigned t, num_vertices, num_edges, num_acorns, num_trees;
  stringstream ss;
  string line;
  bitset<26> has_edge;
  cin >> t;
  cin.ignore();
  while (t--){
    num_vertices = num_edges = num_acorns = num_trees = 0;
    has_edge.reset();
    while (true){
      getline(cin, line);
      if (line[0] == '*'){
        break;
      }
      num_edges++;
      has_edge.set(line[1] - 'A');
      has_edge.set(line[3] - 'A');
    }
    getline(cin, line);
    ss = stringstream(line);
    while (getline(ss, line, ',')){
      num_vertices++;
      if(!has_edge[line[0] - 'A']){
        num_acorns++;
      }
    }
    num_trees = num_vertices - num_edges - num_acorns;
    cout << "There are " << num_trees << " tree(s) and " << num_acorns << " acorn(s)." << endl;
  }
  return 0;
}