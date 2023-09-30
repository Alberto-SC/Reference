
#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        int cont = 0;
        for(int i = 0;i<n/2;){
            int j = i;
            while(j<n/2 && s[j]!= s[n-j-1]){
                j++;
            }
            if(j == i)j++;
            else cont++;
            i = j;
        }
        if(cont<=1){cout<<"YES"<<endl;}
        else cout<<"NO"<<endl;
   }
    return 0;
}

