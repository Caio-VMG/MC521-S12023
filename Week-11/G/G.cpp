#include <iostream>
#include <vector>
 
int main() {
    unsigned t, m, n, i, j;
    int max_id;
    std::vector<std::vector<int>> a;
    std::vector<int> last, ans;
    
    for (std::cin >> t; t > 0; t--) {
        max_id = 0;
        std::cin >> m;
    
        a.resize(m);
        ans.resize(m);
    
        for (i=0; i<m; i++) {
            std::cin >> n;
            a[i].resize(n);
    
            for (j = 0; j <n; j++) {
                std::cin >> a[i][j];
    
                if (max_id < a[i][j]) {
                    max_id = a[i][j];
                }
            }
    
            ans[i] = -1;
        }
        last.resize(max_id + 1);
    
        for (i=0; i<m; i++) {
            for (j = 0; j < a[i].size(); j++) {
                last[a[i][j]] = i;
            }
        }
    
        for (i=0; i<m; i++) {
            for (j = 0; j < a[i].size(); j++) {
                if (last[a[i][j]] == (int) i) {
                    ans[i] = a[i][j];
                }
            }
    
            if (ans[i] == -1) {
                std::cout << -1 << std::endl;
                break;
            }
        }
    
        if (i == m) {
            for (i=0; i+1<m; i++) {
                std::cout << ans[i] << ' ';
            }
            std::cout << ans[m-1] << std::endl;
        }
    }
    return 0;
}