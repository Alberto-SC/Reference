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
        bool palindrome = true;
        for(int i = 0;i<n/2;i++)
            if(s[i]!= s[(n-1)-i])palindrome= false;
        if(palindrome)cout<<1<<endl;
        else if(k==0)cout<<1<<endl;
        else cout<<2<<endl;    
     
    }
    return 0;
}