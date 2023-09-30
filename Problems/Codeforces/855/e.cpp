#include <bits/stdc++.h>
#define ing long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        string s,t;
        cin>>s>>t;
        
        string ss = s,st = t;
        sort(ss.begin(),ss.end());
        sort(st.begin(),st.end());

        if(ss !=st){
            cout<<"NO"<<endl;
            continue;
        }

        bool flag = true;
        for(int i = 0;i<n;i++){
            if(i-k<0 && i+k>=n && s[i]!=t[i])flag = false;
        }

        if(!flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    
}

