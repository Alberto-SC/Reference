#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        string a,b;
        cin>>a>>b;
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            if(a[i]!= b[i] && a[i+1]!= b[i+1] && a[i]!= a[i+1]){
                ans++;
                a[i] =char('0'+(1-(a[i]-'0')));
                a[i+1] =char('0'+(1-(a[i+1]-'0')));
            }
        }
        for(int i = 0;i<n;i++){
            if(a[i]!= b[i]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
