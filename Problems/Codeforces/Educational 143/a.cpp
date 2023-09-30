#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 

using namespace std;
signed main(){__
    int T,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        reverse(t.begin(),t.end());
        s+=t;
        int cont = 0;
        for(int i = 1;i<s.size();i++){
            if(s[i]== s[i-1]){
                cont++;
            }
        }
        if(cont<=1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
