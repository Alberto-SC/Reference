#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool notPrime(int n){
    for(int i = 2;i*i<=n;i++){
        if(n%i==0)return true;
    }
    return false;
}

signed main(){__
	int t= 1,n;
    set<char> ans = {'1','4','6','8','9'};
    vector<int> ans2;
    for(int i = 11;i<=99;i++){
        if(notPrime(i))
            ans2.push_back(i);
    }
    cin>>t;
    while(t--){
        string s;
        cin>>n;
        cin>>s;
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(ans.count(s[i])){
                cout<<1<<endl;
                cout<<s[i]<<endl;
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        string res;
        for(int i = 0;i<ans2.size();i++){
            string x = to_string(ans2[i]);
            vector<int> b(10);
            int idx = 0;
            for(int j = 0;j<n;j++)
                if(idx<x.size() && s[j]==x[idx])
                    idx++;
            bool f = false;
            if(idx == x.size())
                f = true;
            if(f){
                res = x;
                break;
            }
        }
        cout<<2<<endl;
        cout<<res<<endl;
    }
    return 0;
}  
