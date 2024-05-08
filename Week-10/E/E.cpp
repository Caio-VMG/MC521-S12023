#include <iostream>
#include <cmath>
 
#define ll long long
 
using namespace std;
 
int main() {
    int t, l, r, x, a, b;
    cin >> t;
 
    while (t--) {
        cin >> l >> r >> x >> a >> b;
        int ans = -1;
        if (a == b) {
            ans = 0;
        }
        else if (abs(a-b) >= x) {
            ans = 1;
        }
        else if (a+x > r && a-x < l) {
            ans = -1;
        }
        else if (b > a) {
            if (x + b <= r || a - x >= l) {
                ans = 2;
            }
            else if (abs(b-l) >= x && abs(r-a) >= x) {
                ans = 3;
            }
        }
        else if (b < a) {
            if (b - x >= l || a + x <= r) {
                ans = 2;
            }
            else if (abs(r-b) >= x && abs(a-l) >= x) {
                ans = 3;
            }
        }
 
        cout << ans << endl;
    }
 
    return 0;
}