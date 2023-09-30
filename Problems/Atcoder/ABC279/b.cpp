#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        string s,t;
        cin>>s>>t;
        if(t.size()>s.size())return cout<<"No"<<endl,0;
        int n= s.size();
        int m =t.size();
        for(int i = 0;i<(n-m)+1;i++){
            bool flag = true;
            for(int j = 0;j<m;j++){
                if(s[i+j]!=t[j])flag = false;
            }
            if(flag)return cout<<"Yes"<<endl,0;
        }
        cout<<"No"<<endl;
    }
    return 0;
}