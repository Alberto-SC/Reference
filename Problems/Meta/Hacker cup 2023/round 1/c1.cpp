#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int b[4000007];
signed main(){__
	int T= 1,n,Q,x;
    int id = 1;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        cin>>Q;

        for(int i = 0;i<Q;i++){
            cin>>x;
            b[x]^=1;
        }

        for(int i = 1;i<=n;i++){
            if(b[i]==0)continue;
            for(int j = 1;j*i<=n;j++){
                if(s[(i*j)-1]=='0')s[(i*j)-1] = '1';
                else s[(i*j)-1] = '0';
            }
        }


        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(s[i-1]=='0')continue;
            ans++;
            for(int j = 1;j*i<=n;j++){
                if(s[(i*j)-1]=='0')s[(i*j)-1] = '1';
                else s[(i*j)-1] = '0';
            }
        }

        cout<<"Case #"<<id<<": "<<ans<<endl;
        for(int i = 1;i<=n;i++){
            b[i] = 0;
        }
        id++;
    }
    return 0;
}  

