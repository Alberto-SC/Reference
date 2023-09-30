#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,l,r;
    cin>>n>>l>>r;
    vector<int> ans(n+1);
    iota(ans.begin(),ans.end(),0);

    vector<pair<int,int>> op; 
    op.push_back({0,0});
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            op.push_back({i,j});
        }
    }

    // for(int i = 0;i<op.size();i++){
    //     cout<<"("<<op[i].first<<" , "<<op[i].second<<") ";
    // }
    // cout<<endl;
    for(int i = l;i<=r;i++){
        swap(ans[op[i].first],ans[op[i].second]);
    }

    for(int i = 1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}