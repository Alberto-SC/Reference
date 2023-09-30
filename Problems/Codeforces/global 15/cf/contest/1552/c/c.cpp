#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k,u,v;
    cin>>t;
    int x = 1;
    for(int i = 1;i<=29;i+=2){
        x*=i;
    }
    cout<<x<<endl;
    while(t--){
        cin>>n>>k;
        vector<int> init(n+1);
        for(int i = 1;i<=k;i++){
            cin>>u>>v;
            init[u] = i;
            init[v] = i;
        }
        vector<int> f;
        for(int i = 1;i<=n;i++){
            if(!init[i])
                f.push_back(i);
        }
        int N = f.size();
    

    }
    return 0;
}  
