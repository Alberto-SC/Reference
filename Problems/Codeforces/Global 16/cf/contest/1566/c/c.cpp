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
        string a,b;
        cin>>a>>b;
        int ans = 0,z = 0,o = 0,x = 0;
        for(int i = 0;i<n;i++){
            z+=a[i]=='0';
            z+=b[i]=='0';
            o+=a[i]=='1';
            o+=b[i]=='1';
            if((z>0 && o>0)){
                int h = x;
                if(a[i]!= b[i])x+=2;
                else x++;
                ans +=max(2ll,x);
                x = 0;
                z = 0;
                o = 0;
            }
            else if(a[i]==b[i] && a[i]=='0'){
                x++;
            }
        }
        ans+=x;
        cout<<ans<<endl;
    }
    return 0;
}  
