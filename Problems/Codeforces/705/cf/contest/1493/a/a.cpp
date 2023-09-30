#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> ans;
        for(int i =(k+1)/2;i<k;i++)
            ans.push_back(i);
        
        for(int i = k+1;i<=n;i++)
            ans.push_back(i);
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
