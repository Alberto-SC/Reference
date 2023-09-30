#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    
    int x = 1;
    vector<int> ans;
    ans.push_back(1);
    
    int turn = 0;
    while(x<1e18){
        if(!turn)x*=2;
        else x++;
        ans.push_back(x);
        turn ^=1;
    }
    while(T--){
        cin>>n;
        cout<<ans[n]<<endl;
    }
    
}


