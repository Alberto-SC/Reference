#include <bits/stdc++.h>
using namespace std;
struct Matrix {
    int n;
    vector<vector<unsigned>> val;
    Matrix () {}
    Matrix (int _n) {
        n = _n;
        val.assign(n, vector<unsigned>(n, 0));
    }
    vector<unsigned>& operator[] (int i) {
        return val[i];
    }
    Matrix operator* (Matrix a) {
        Matrix ans(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    ans[i][k] += val[i][j] * a[j][k];
        return ans;
    }
    vector<unsigned> operator* (vector<unsigned> a) {
        vector<unsigned> ans(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans[j] += val[i][j] * a[i];
        return ans;
    }
};
 
int sq(int x) {
    return x * x;
}
 
const int BASE = 7;
const int LOG = 30;
 
vector<int> step[BASE], pref_sum[BASE];
int siz[BASE];
 
void precalc_steps(int base) {
    step[base].resize(base);
    pref_sum[base].resize(base + 1);
    int sz = 0;
    for (int i = 0; i < base; ++i) {
        pref_sum[base][i] = sz;
        step[base][i] = sq(max(i, base - 1 - i));
        sz += step[base][i];
    }
    pref_sum[base][base] = sz;
    siz[base] = sz;
}
 
Matrix transitions(int base) {
    Matrix ans(siz[base]);
    for (int i = 0; i < base; ++i) {
        for (int j = 1; j < step[base][i]; ++j)
            ans[pref_sum[base][i] + j][pref_sum[base][i] + j - 1] = 1;
        for (int j = 0; j < base; ++j) {
            if (j == i) continue;
            ans[pref_sum[base][j + 1] - sq(i - j)][pref_sum[base][i + 1] - 1] = 1;
        }
    }
    return ans;
}
 
vector<unsigned> start(int base) {
    vector<unsigned> ans(siz[base]);
    for (int i = 1; i < base; ++i)
        ans[pref_sum[base][i + 1] - 1] = 1;
    return ans;
}
 
Matrix pw[BASE][LOG];
 
void precalc_powers(int base) {
    pw[base][0] = transitions(base);
    for (int i = 1; i < LOG; ++i)
        pw[base][i] = pw[base][i - 1] * pw[base][i - 1];
}
 
void precalc() {
    for (int i = 2; i < BASE; ++i) {
        precalc_steps(i);
        precalc_powers(i);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    precalc();
    int t;
    cin >> t;
    for (int _ = 1; _ <= t; ++_) {
        int b, sc;
        cin >> b >> sc;
        vector<unsigned> v = start(b);
        for (int i = 0; i < LOG; ++i)
            if (sc & (1 << i))
                v = pw[b][i] * v;
        unsigned ans = 0;
        for (int i = 0; i < b; ++i)
            ans += v[pref_sum[b][i + 1] - 1];
        cout << "Case " << _ << ": " << ans << '\n';
    }
}