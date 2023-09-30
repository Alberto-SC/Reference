#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        map<int,int> mp;

        vector<int> A(n);
        vector<int> B(n);
        for(int i = 0;i<n;i++)
            cin>>A[i];
        for(int i= 0;i<n;i++){
            cin>>B[i];
            if(mp.count(A[i]))
                mp[A[i]] = min(mp[A[i]],B[i]);
            else mp[A[i]] = B[i];
        }

        vector<int> best;
        for(auto c:mp){
            best.push_back(c.second);
        }
        sort(best.begin(),best.end());
        int ans = 0;
        if(best.size()<k){
            cout<<-1<<endl;
            continue;
        }
        for(int i = 0;i<k;i++){
            ans+=best[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}