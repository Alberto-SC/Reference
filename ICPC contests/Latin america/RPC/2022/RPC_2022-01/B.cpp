#include <bits/stdc++.h>
#define endl '\n'
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
using namespace std;

using ld = long double;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MX = 2 * 1e5 + 5;

vector<int> sa(MX);
void countingSort (string &s, int ra[], int k ) {
    int t_sa[MX] = {0}, c[MX] = {0}, sum, n = s.size(), mx = max(300, n);
    for (int i = 0; i < n; i++)
        c[i+k<n?ra[i+k]:0]++;
    for (int i = sum = 0; i < mx; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (int i = 0; i < n; i++)
        t_sa[c[sa[i]+k<n?ra[sa[i]+k]:0]++] = sa[i];
    for (int i = 0; i < n; i++) sa[i] = t_sa[i];
}
void obtSA (string& s) {
    int t_ra[MX] = {0}, ra[MX] = {0}, r, n = s.size();
    for (int i = 0; i < n; i++) ra[i] = s[i];
    for (int i = 0; i < n; i++) sa[i] = i;
    for (int k = 1; k < n; k <<= 1) {
        countingSort(s, ra, k);
        countingSort(s, ra, 0);
        t_ra[s[0]] = r = 0;
        for (int i = 1; i < n; i++)
            if (ra[sa[i]] == ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k])
                t_ra[sa[i]] = r;
            else
                t_ra[sa[i]] = ++r;
        for (int i = 0; i < n; i++) ra[i] = t_ra[i];
        if (ra[sa[n-1]] == n-1) break;
    }
}

struct WaveletTree{
    int lo, hi;
    WaveletTree *left, *right;
    vector<int> freq;

    WaveletTree(vector<int>::iterator from, vector<int>::iterator to, int x, int y): lo(x), hi(y){
        if(from >= to) return;
        int m = (lo + hi) / 2;
        auto f = [m](int x){return x <= m;};
        freq.reserve(to - from + 1);
        freq.push_back(0);
        for(auto it = from; it != to; ++it){
            freq.push_back(freq.back() + f(*it));
        }
        if(hi != lo){
            auto pivot = stable_partition(from, to, f);
            left = new WaveletTree(from, pivot, lo, m);
            right = new WaveletTree(pivot, to, m + 1, hi);
        }
    }

    int kth(int l, int r, int k){
        if(l > r) return 0;
        if(lo == hi) return lo;
        int lb = freq[l - 1], rb = freq[r];
        int inLeft = rb - lb;
        if(k <= inLeft) return left->kth(lb + 1, rb, k);
        else return right->kth(l - lb, r - rb, k - inLeft);
    }
};

int bin_lo(const string& t, const string& s, int n){
    int izq = 0, der = n;
    while(izq < der){
        int med = (izq + der) / 2;
        string aux = s.substr(sa[med], min(n - sa[med], (int)t.size()));
        if(aux >= t){
            der = med;
        }else{
            izq = med + 1;
        }
    }
    return izq;
}

int bin_hi(const string& t, const string& s, int n){
    int izq = 0, der = n;
    while(izq < der){
        int med = (izq + der) / 2;
        string aux = s.substr(sa[med], min(n - sa[med], (int)t.size()));
        if(aux > t){
            der = med;
        }else{
            izq = med + 1;
        }
    }
    return izq;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    s += "$";

    int n = s.size();

    obtSA(s);

    vi temp_sa = sa;

    WaveletTree *wt = new WaveletTree(sa.begin(), sa.end(), 0, MX);

    sa = temp_sa;

    int q;
    cin >> q;

    while(q--){
        string t;
        cin >> t;

        int k;
        cin >> k;

        int ini = bin_lo(t, s, n);
        int fin = bin_hi(t, s, n);
        if(fin - ini < k){
            cout << -1 << endl;
        }else{
            cout << wt->kth(ini + 1, fin, k) + 1 << endl;
        }
    }

    return 0;
}

