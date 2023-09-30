#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        int c = 0;
        for(int i= 0;i<n/2;i++)
            if(s[i]!=s[n-1-i])c++;
        if(c==k|| (c<k && n&1)|| (c<k &&(((k-c)%2)==0)))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}