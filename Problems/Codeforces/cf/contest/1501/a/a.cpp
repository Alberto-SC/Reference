#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> tm(n);
        for(int i = 0;i<n;i++)
            cin>>a[i]>>b[i];
        
        for(auto &c:tm)cin>>c;
        int lastb = 0,arrive,th,leave = 0;
        int time = 0;
        for(int i = 0;i<n;i++){
            arrive = leave+(a[i]-lastb)+tm[i];
            th = ceil((b[i]-a[i])/2.0);
            leave = arrive+th;
            if(leave<b[i])leave = b[i];
            lastb = b[i];
            // cout<<arrive<<" "<<leave<<endl;
        }
        cout<<arrive<<endl;
    }
    return 0;
}  
