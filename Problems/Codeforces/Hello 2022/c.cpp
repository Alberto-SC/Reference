#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n; 
    cin>>t;
    while(t--){
        cin>>n;
        vector<vector<int>> cycle;
        vector<bool> x(n+1,false);
        int y;
        for(int i= 1;i<=n;i++){
            bool first =  true;
            vector<int> h;
            int f;
            if(!x[i]){
                while(1){
                    cout<<"? "<<i<<endl;
                    cin>>y;
                    if(y==f && !first){
                        break;
                    }
                    if(first)
                        f = y;
                    x[y] = true;
                    h.push_back(y);
                    first = false;
                }
            }
            if(h.size())
                cycle.push_back(h);
        }
        vector<int> ans(n);
        for(int i= 0;i<cycle.size();i++){
            for(int j = 1;j<=cycle[i].size();j++){
                ans[cycle[i][j-1]-1] = cycle[i][j%cycle[i].size()];
            }
        }
        cout<<"! ";
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
