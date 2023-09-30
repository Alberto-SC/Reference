#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> nums(n);
        vector<int> b(m);
        for(auto &c:nums)cin>>c,c%=m,b[c]++;
        int cont = 0;
        // cout<<m/2<<endl;
        for(int i = 1;i<=m/2;i++){
            int mn  = min(b[i],b[m-i]);
            cont+=max(b[i],b[m-i])-mn;
            if(b[i]== b[m-i] && b[i])cont++;
        }
        if(b[0])cont++;
        cout<<cont<<endl;
    }
    return 0;
}  
