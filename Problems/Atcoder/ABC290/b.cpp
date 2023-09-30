#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;

    string ans(n,'x');
    for(int i = 0;i<n;i++){
        if(s[i]== 'o' && k){
            k--;
            ans[i]  ='o';
        }
    }
    cout<<ans<<endl;
    return 0;
}
