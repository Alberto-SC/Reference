#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n == 3){
            cout<<2<<endl;
            cout<<3<<" "<<2<<endl;
            cout<<3<<" "<<2<<endl;
            continue;
        }
        int sqr = ceil(sqrt(n*1.0));
        int sqr2 = ceil(sqrt(sqr));
        vector<pair<int,int>> ans;
        for(int i = 3;i<n;i++){
            if(sqr2>=3 && i == sqr2)continue;
            if(i == sqr)continue;
            ans.push_back({i,n});
        }
        ans.push_back({n,sqr});
        ans.push_back({n,sqr});
        int idx = sqr;
        int idx2 = sqr2;
        // cout<<sqr<<endl;
        if(sqr2>=3){
            ans.push_back({sqr,sqr2});
            ans.push_back({sqr,sqr2});
            while(sqr2>1){
                ans.push_back({idx2,2});
                sqr2 = (sqr2+1)/2;
            }
        }
        else{
            if(sqr>2){
                while(sqr>1){
                    ans.push_back({idx,2});
                    sqr = (sqr+1)/2;
                }
            }
        }
        cout<<ans.size()<<endl;
        assert(ans.size()<=n+5);
        for(auto [u,v]:ans)cout<<u<<" "<<v<<endl;
    }
    return 0;
}  

