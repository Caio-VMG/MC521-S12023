#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(const vector<vector<unsigned>> &adj, unsigned u, unsigned excluded,
         vector<bool> &visited) {
  unsigned v;
  // Não busca a partir do vertice excluido
  if (u != excluded) {
    visited[u] = true;
    // Itera para cada vertice v adjacente a u
    for (v = 0; v < adj[u].size(); v++) {
      if (adj[u][v] and !visited[v]) {
        dfs(adj, v, excluded, visited);
      }
    }
  }
}

int main() {
  unsigned t, c, n, u, v;
  // matriz de adj
  vector<vector<unsigned>> adj;
  // marcador de vercice visitados
  vector<bool> visited_from_start, visited;
  // matriz que armazena as relações de dominancia
  vector<vector<bool>> ans;
  string separator;
  cin >> t;
  for (c = 1; c <= t; c++) {
    cin >> n;
    adj.resize(n);
    adj.assign(n, vector<unsigned>(n, 0));
    visited_from_start.resize(n);
    visited_from_start.assign(n, false);
    visited.resize(n);
    ans.resize(n);
    ans.assign(n, vector<bool>(n, false));

    // le a matriz de adj
    for (u = 0; u < n; u++) {
      for (v = 0; v < n; v++) {
        cin >> adj[u][v];
      }
    }

    // encontra todos vertices alcancaveis
    dfs(adj, 0, n, visited_from_start);
    // para cada vertice alcancaver a partir de 0
    for (u = 0; u < n; u++) {
      if (visited_from_start[0]) {
        visited.assign(n, false);

        // ecnontra os vertices não ancaveis quando ele é excluido
        dfs(adj, 0, u, visited);

        // Se o vertice 'v' é alcancavel a partir de 0
        // mas não é alcançável quando 'u' é removido
        // então u domina v
        for (v = 0; v < n; v++) {
          if (visited_from_start[v] and !visited[v]) {
            ans[u][v] = true;
          }
        }
      }
    }
    // exibe resultados
    cout << "Case " << c << ":" << endl;
    separator = "+" + string(2 * n - 1, '-') + "+";
    cout << separator << endl;

    // exibe a matriz de relacoes
    for (u = 0; u < n; u++) {
      for (v = 0; v < n; v++) {
        cout << "|";
        if (ans[u][v]) {
          cout << "Y";
        } else {
          cout << "N";
        }
      }
      cout << "|" << endl;
      cout << separator << endl;
    }
  }
  return 0;
}