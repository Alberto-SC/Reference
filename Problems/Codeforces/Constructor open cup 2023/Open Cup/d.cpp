#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'


using namespace std;

signed main(){
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        string ans = "";
        while(n>1){
            int x = (n-1)/2;
            if(x&1)ans+="2",n = x;
            else n =(n+1)/2,ans+="1";
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}

