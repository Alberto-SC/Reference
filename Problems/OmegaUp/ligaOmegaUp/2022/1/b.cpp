#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    int id = 1;
    while(t--){
        string s;
        cin>>s;
        string p = "facebook";
        int idx = 0;
        n = s.size();   
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(idx<(int)p.size() && s[i]==p[idx])idx++;
        }
        if(idx==(int)p.size())flag = true;
        if(flag)
            cout<<"Case #"<<id<<": YES"<<endl;
        else cout<<"Case #"<<id<<": NO"<<endl;
        id++;
    }
    return 0;
}  
