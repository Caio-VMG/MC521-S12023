#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
 
void solution(int n, vector<int> a){
    int pares = 0;
    int impares = 0;
    int pares_certos = 0;
    int impares_certos = 0;

    for(int i = 0; i<n; i++){
        if(a[i]%2 == 0){
            pares++;
            if(i%2 == 0){
                pares_certos++;
            }

        }
        else{
            impares++;
            if(i%2 == 1){
                impares_certos++;
            }
        }
    }

    if(impares_certos == impares and pares_certos == pares){
        cout << 0 << endl;
        return;
    }
    if(pares - pares_certos != impares - impares_certos){
        cout << -1 << endl;
        return;
    }

    cout << pares - pares_certos << endl;

    return;
}
 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> a;

        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            a.push_back(k);

        }

        solution(n, a);
    }
    return 0;
}