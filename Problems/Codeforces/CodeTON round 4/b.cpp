#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> ans;
        if(n%2 == 0){
            cout<<-1<<endl;
            continue;
        }

        while(n>1){
            int x = (n-1)/2;
            if(x%2 == 0)n = (n+1)/2,ans.push_back(1);
            else n = x,ans.push_back(2);
        }

        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
}


