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
        vector<int> nums(n);
        bool s = false;
        for(auto &c:nums)cin>>c,s|=c<0;
        if(s)cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl;
            cout<<100<<endl;
            for(int i = 1;i<=100;i++)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  
