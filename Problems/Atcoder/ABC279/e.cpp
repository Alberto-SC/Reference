#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    for (int &i: a) {
        cin >> i;
    }
    
    vector<int> b(n + 1);
    iota(b.begin(), b.end(), 0);
    for (int i: a) {
        swap(b[i], b[i + 1]);
    }
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) 
        pos[b[i]] = i;

    iota(b.begin(), b.end(), 0);
    for (int i: a) {
        if (b[i] == 1) 
            cout<<pos[b[i + 1]]<<endl;
        else if (b[i + 1] == 1) 
            cout<<pos[b[i]]<<endl;
        else 
            cout<<pos[1]<<endl;
        swap(b[i], b[i + 1]);
    }
}
