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
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        forn(i, n) cin >> a[i];
        int i = 0;
        ll res = 0;
        while(i < n - 1){
            if(a[i] > a[i + 1]){
                int j = i + 1;
                while(j < n && a[j - 1] > a[j]) j++;
                j--;
                res += (ll)(a[i] - a[j]);
                i = j;
            }
            i++;
        }
        cout << res << endl;
    }
 
    return 0;
}
 n  