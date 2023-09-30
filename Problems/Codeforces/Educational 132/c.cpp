#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool valid(string s){
    int ac = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i]=='(')ac++;
        else ac--;
        if(ac<0)return false;
    }
    return true;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        n = s.size();
        int a = n/2,b =n/2;
        vector<int> need;
        for(int i = 0;i<n;i++){
            if(s[i]=='(')a--;
            else if(s[i]==')')b--;
            else need.push_back(i);
        }

        for(int i = 0;i<need.size();i++){
            if(i<a)s[need[i]] = '(';
            else s[need[i]] = ')';
        }
        if(a && b){
            swap(s[need[a-1]],s[need[a]]);
        }
        if(valid(s) && a && b)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}