#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        string ans = "";
        string last = "";
        bool flag = false;
        for(int i = 0;i<n-2;i++){
            string x;
            cin>>x;
            if(i==0)ans+=x;
            else {
                if(x[0]!=last[1]){
                    flag = true;
                    ans+=x[0];
                    ans+=x[1];
                }
                else
                    ans+=x[1];
            }
            last = x;
        }
        if(!flag)ans+="a";
        cout<<ans<<endl;
    }
    return 0;
}