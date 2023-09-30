#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>n;
    string q(n,'1');
    vector<pair<int,int>> v;
    for(int i = 1;i<=n;i++){
        string qq =q ;
        qq[i-1] = '0'; 
        cout<<"? "<<i<<" "<<qq<<endl;
        int x;cin>>x;
        v.push_back({x,i-1});
    }
    sort(v.rbegin(),v.rend());
    string ans(n,'0');
    q = string (n,'0');
    ans[v[0].second]= '1';    
    q[v[0].second]= '1';    
    for(int i = 1;i<n;i++){
        cout<<"? "<<v[i].second+1<<" "<<q<<endl;
        int x;cin>>x;
        q[v[i].second] = '1';
        
        if(x)q[v[i].second] = '1';
    }
    cout<<"! "<<ans<<endl;
    return 0;
}