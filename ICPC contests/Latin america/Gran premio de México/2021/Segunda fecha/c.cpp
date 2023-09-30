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
        int idx = -1, mn = 1e15,sum = 0;
        for(int i = 0;i<n;i++){
            sum+= s[i]=='B'?1:-1;
            if(sum<mn){
                mn = sum;
                idx = i+1;
            }
        }
        if(mn == 0)idx = 0;
        cout<<idx<<endl;
    }
    return 0;
}  
