#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main (){ __

    int m, n; cin>>m>>n;
    vector<int> sc(n);
    int fullspaces = 0;

    for(int i = 0; i < n; i++){
        cin>>sc[i];
        fullspaces += sc[i];
    }

    vector<int> res (n, 0);
    int contspaces = 0;

    while( (m != 0) && (contspaces != fullspaces) ){

        for(int i = 0; i < n; i++){
            if(sc[i] != 0){
                sc[i]--;
                res[i]++;
                m--;
                contspaces++;
            }
            if(m == 0 || contspaces == fullspaces) break;
        }

    }

    for(int x: res) cout << x << "\n";
    return 0;
}