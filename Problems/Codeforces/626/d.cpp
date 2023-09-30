#include <bits/stdc++.h>
 
using namespace std;
 
  
int main() {
    size_t n;
    cin >> n;
    vector<int64_t> v(n);
    for(size_t i = 0; i < n; i++) {
        cin >> v[i];
    }
    int64_t sol = 0;
    for(size_t bit = 1; bit < 28; bit++) {
        vector<int> w(n);
        for(size_t i = 0; i < n; i++) {
            w[i] = v[i] & ((1 << bit) - 1);
        }
        sort(w.begin(), w.end());
        /*cerr << "BIT " << bit << endl;
        cerr << w << endl;*/
        int64_t cnt = 0;
        for(size_t i = 0; i < n; i++) {
            int64_t lb = (1LL << (bit - 1LL)) - w[i];
            int64_t ub = ((1LL << bit) - 1LL) - w[i];
            auto lbi = lower_bound(w.begin() + i + 1, w.end(), lb);
            auto ubi = upper_bound(w.begin() + i + 1, w.end(), ub);
            cnt += ubi - lbi;
            lb = (1LL << (bit - 1LL)) + (1LL << bit) - w[i];
            ub = ((1LL << bit) - 1LL) + (1LL << bit) - w[i];
            lbi = lower_bound(w.begin() + i + 1, w.end(), lb);
            ubi = upper_bound(w.begin() + i + 1, w.end(), ub);
            cnt += ubi - lbi;
        }
        // cerr << cnt << endl << endl;
        if(cnt % 2 == 1) {
            sol = sol | (1 << (bit - 1));
        }
    }
    cout << sol << endl;
    return 0;
}