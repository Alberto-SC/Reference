#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        string s;
        char c;
        cin>>s;
        cin>>c;
        n = s.size();
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(s[i]==c){
                if(i%2==0 && (n-i)&1)
                    flag = true;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}   