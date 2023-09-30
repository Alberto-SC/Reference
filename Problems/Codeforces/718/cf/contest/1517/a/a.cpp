#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    vector<int> nm;
    int x = 2050;
    for(int i = 0;i<16;i++){
        nm.push_back(x);
        x*=10;
    }
    cin>>t;
    while(t--){
        cin>>n;
        if(n%2050)cout<<-1<<endl;
        else{
            int ans = 0;
            for(int i = nm.size()-1;i>=0;i--){
                ans+= n/nm[i];
                n-= (n/nm[i])*nm[i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}  
