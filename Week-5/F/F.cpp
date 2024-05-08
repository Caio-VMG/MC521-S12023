#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
 
string solution(int n, vector<int> set){
    int sum = 0;
    for(int i = 0; i< n; i++){
        if(set[i] == 1){
            sum++;
        }
    }
    if(sum == 0){
        if(n%2 == 0){
            return "YES";
        }
        return "NO";
    }
    
    if(sum%2 == 0){
        return "YES";
    }
    return "NO";
}
 
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> set;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            set.push_back(k);
        }
        cout << solution(n, set) << endl;
    }
    return 0;
}