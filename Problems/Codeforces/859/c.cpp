#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        vector<int> a(26,-1);
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(i&1){
                if(a[s[i]-'a']==0)flag = false;
                a[s[i]-'a'] = 1;
            }
            else{
                if(a[s[i]-'a']==1)flag = false;
                a[s[i]-'a'] = 0;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

     
    }
    return 0;
}

