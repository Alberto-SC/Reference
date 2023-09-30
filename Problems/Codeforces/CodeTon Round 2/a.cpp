#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        int id = m-1;
        int id2 = n-1;
        while(id>=0){
            if(s[id2]!=t[id])break;
            id2--;
            id--;
        }
        if(id<0)cout<<"YES"<<endl;
        else if(id>=1)cout<<"NO"<<endl;
        else{
            bool flag = false;
                for(int i = 0;i<id2;i++){
                    if(s[i]==t[0])
                        flag = true;
                }
            if(flag)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}