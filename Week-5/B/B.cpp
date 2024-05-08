#include <iostream>
#include <vector>
 
using namespace std;
 
bool solvable(int n, int k, int r) {
    if (n < k) return false;
    if (n % 2 == 0 && k % 2 == 1 && n < k*2) return false;
    if (n % 2 == 1 && k % 2 == 0) return false;
    return true;
}
 
void solution(int n, int k) {
    int r = n/k;
    if (n % 2 == 0 && k % 2 == 1 & r % 2 == 1) {
        r--;
    }
    if (n % 2 == 1 && k % 2 == 1 & r % 2 == 0) {
        r--;
    }
    if (solvable(n, k, r)) {
        int rem = n - ((k-1)*r);
        cout << "YES" << endl;
        for (int i = 0; i < k-1; i++) {
            cout << r << ' ';
        }
        cout << rem << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
 
        solution(n, k);
    }
    return 0;
}