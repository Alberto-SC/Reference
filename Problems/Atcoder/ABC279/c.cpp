#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int n,m;
    cin>>n>>m;
    vector<string> S(n),T(n);
    for(int i = 0;i<n;i++){
        cin>>S[i];
    }
    for(int i = 0;i<n;i++){
        cin>>T[i];
    }

    vector<string> a(m),b(m);

    for(int j = 0;j<m;j++){
        for(int i = 0;i<n;i++){
            a[j].push_back(S[i][j]);
            b[j].push_back(T[i][j]);
        }
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    bool flag = true;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j]!=b[i][j])flag = false;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}