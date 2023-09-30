#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1e9+7;
int main(){__
    int t = 1,n;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        vector<int> a;
        vector<int> b;
        vector<int> c;
        vector<int> q;
        lli ans =1;
        for(int i = 0;i<n;i++){
            if(s[i]== 'a')a.push_back(i);   b
            if(s[i]== 'b')a.push_back(i);
            if(s[i]== 'c')a.push_back(i);
            if(s[i]== '?')a.push_back(i);
        }
        for(int i = 0;i<n;i++){
            if(s[i] == 'a' || s[i]== '?'){
                ans*=

                ans%=mod;
            }
        }
        cout<<ans<<emdl;
    }
    return 0;
}

