#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <map>
using namespace std;
 

map<char, int> solvePath(string a, int begin, int end, char c, int n, map<char, int> m){
    int k = 0;
    char letra = a[begin];
    bool pegou = false;
    int b = begin;
    for(int i = begin+1; i<end; i++){
        if(letra == a[i] and !pegou){
            m = solvePath(a, b+1, i, letra, 1, m);
            n++;
            pegou = true;
        } else if(pegou){
            pegou = false;
            b = i;
            letra = a[i];
        }
    }
    m[c] = n;
    return m;
} 

void solution(int i, string a){
    map<char, int> m;
    m = solvePath(a, 1, a.size()-1, a[0], 0, m);

    map<char, int>::iterator it;
    cout << "Case " << i<< endl;
   for(it=m.begin(); it!=m.end(); ++it){
      cout << it->first << " = " << it->second << endl;;
   }

    return;
}
 

int main()
{
    int t;
    cin >> t;
    int tt = t;
    while (t--)
    {
        string a;

        cin >> a;

        solution(tt-t, a);
    }
    return 0;
}