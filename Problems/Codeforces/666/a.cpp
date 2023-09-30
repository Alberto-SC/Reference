#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> b(26,0);
        for(int i = 0;i<n;i++){
            cin>>s;
            for(int j = 0;j<s.size();j++){
                b[s[j]-'a']++;
            }
        }
        bool flag = true;
        for(int i = 0;i<26;i++)
            if(b[i]%n!= 0)flag = false;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    
    }
    return 0;
}

