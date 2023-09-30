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

const int MX = 1e5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int wc, hc;
    cin >> wc >> hc;
    int ws, hs;
    cin >> ws >> hs;

    ws += 2;
    hs += 2;

    cout << (ws <= wc && hs <= hc) << endl;

    return 0;
}

