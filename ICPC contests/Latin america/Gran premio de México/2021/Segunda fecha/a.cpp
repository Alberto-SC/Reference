#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        int idx = -1, mn = 1e15;
        for(int i = 0;i<n;i++){
            s+= s[i]=='B'?1:-1;
            if(s<mn){
                s = mn;
                idx = i+1;
            }
        }
        cout<<idx<<endl;
    }
    return 0;
}  
