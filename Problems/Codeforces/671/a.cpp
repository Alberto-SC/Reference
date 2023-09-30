#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        bool odd = false;
        bool even = false;
        for(int i = 0;i<n;i++){
            if(i%2 == 0 && (s[i]-'0')&1)odd = true;
            else if(i&1 && (s[i]-'0')%2 ==0)even = true;
        }
        if(n&1){
            if(odd)cout<<1<<endl;
            else cout<<2<<endl;
        }
        else{
            if(even)cout<<2<<endl;
            else cout<<1<<endl;
        }
    }
    return 0;
}

