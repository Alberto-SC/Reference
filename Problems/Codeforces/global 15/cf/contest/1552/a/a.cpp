#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s,t;
        cin>>s;
        t = s;
        sort(t.begin(),t.end());
        int k = 0;
        for(int i = 0;i<n;i++)
            if(s[i]!=t[i])k++;
        cout<<k<<endl;
    }
    return 0;
}  
