#include <iostream>
#include <vector>
 
using namespace std;
 
int get_cards(vector<int> &n_cards, int h) {
    if (n_cards.size() < h) {
        n_cards.push_back(n_cards[h-2] + 2*h + h-1);
        return n_cards[h-1];
    }
    else return n_cards[h-1];
}
 
int cards_left(int n, vector<int> &n_cards) {
    int rem = n, h = 1;
    while (rem - get_cards(n_cards, h) >= 0) {
        h++;
    }
    rem -= get_cards(n_cards, h-1);
    return rem;
}
 
int main() {
    int t, n;
 
    cin >> t;
    vector<int> n_cards; // n_cards[i] eh o num de cartas para piramide de h = i + 1
    n_cards.push_back(2); // valor de cartas para h = 1
 
    while (t--) {
        int ans = 0;
        cin >> n;
        while (n >= 2) {
            n = cards_left(n, n_cards);
            ans++;
        }
        cout << ans << endl;
    }
}