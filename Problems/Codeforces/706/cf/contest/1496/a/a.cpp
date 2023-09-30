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
        string s;
        cin>>s;
        if(n<(k*2)+1){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag = true;
        for(int i = 0;i<k;i++)
            if(s[i]!= s[(n-i)-1])flag = false;
        
        if(k ==0)cout<<"YES"<<endl;
        else if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
