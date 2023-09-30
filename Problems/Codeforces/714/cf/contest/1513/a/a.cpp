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
        int last = n,first = 1;
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            if(i&1 && k &&i<n-1)ans[i] = last--,k--;
            else ans[i] = first++;
        }
        if(k)cout<< -1<<endl;
        else {
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }  
    }
    return 0;
}  
