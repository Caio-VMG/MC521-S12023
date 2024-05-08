#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Essa resolução utiliza como base o algoritmo de djkistra da página:
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
void solve(list<pair<int, int>> *adj_list, int n, int exit, int timeLimit) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> dist(n, 999999);
  pq.push(make_pair(0, exit));
  dist[exit] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    list<pair<int, int>>::iterator i;
    for (i = adj_list[u].begin(); i != adj_list[u].end(); ++i) {
      int v = i->first;
      int weight = i->second;
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  int result = 0;
  for (int i = 0; i < n; i++) {
    if (dist[i] <= timeLimit) {
      result += 1;
    }
  }
  cout << result << "\n";
}

int main(int argc, char *argv[]) {
  int t, n, e, timeLimit, m, v, u, peso, garb;
  cin >> t;
  while (t--) {
    // cin >> garb;
    cin >> n;
    cin >> e;
    cin >> timeLimit;
    cin >> m;
    e -= 1;
    // cout << t << ", " << n << ", " << e << ", " << timeLimit << ", " << m;
    list<pair<int, int>> *adj_list;
    adj_list = new list<pair<int, int>>[n];
    for (int i = 0; i < m; i++) {
      cin >> v >> u >> peso;
      v -= 1;
      u -= 1;
      adj_list[u].push_back(make_pair(v, peso));
    }
    solve(adj_list, n, e, timeLimit);
    if (t > 0) {
      cout << "\n";
    }
  }
}