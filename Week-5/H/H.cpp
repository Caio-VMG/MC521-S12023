#include <iostream>
#include <vector>
#include <bits/stdc++.h>
 
using namespace std;
 
// código adaptado de https://www.geeksforgeeks.org/coin-change-dp-7/
int count(vector<int> coins, int n, int sum)
{
    // table[i] will be storing the number of solutions for
    // value i. We need sum+1 rows as the table is
    // constructed in bottom up manner using the base case
    // (sum = 0)
    vector<int> table(sum + 1, 0);
 
    // Base case (If given value is 0)
    table[0] = 1;
 
    // Pick all coins one by one and update the table[]
    // values after the index greater than or equal to the
    // value of the picked coin
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            table[j] += table[j - coins[i]];
    return table[sum];
}
 
int main() {
    int t, x;
    cin >> t;
    vector<int> coins = {11, 111};
    while (t--) {
        cin >> x;
        // valores acima de 1099 nao precisam ser verificados
        if (x > 1099 || count(coins, coins.size(), x)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}