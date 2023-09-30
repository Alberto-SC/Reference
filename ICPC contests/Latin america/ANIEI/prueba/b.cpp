#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    vector<int> factorials;
    factorials.push_back(1);
    for(int i = 2;i<=10;i++){
        factorials.push_back(factorials.back()*i);
    }
    while(t--){
        cin>>n;
        int ans = 0;
        while(n){
            int mx = 0;
            for(auto c:factorials){
                if(c<=n)
                    mx = c;
            }
            n-=mx;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
