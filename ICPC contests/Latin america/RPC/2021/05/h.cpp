#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    string s;
    cin>>s;
    n = s.size();
    map<char,int> mp;
    for(int i = 0;i<n;i++){
        mp[s[i]]++;
    }
    bool flag = true;
    for(auto c:mp){
        if(c.second>=2)flag = false;
    }
    cout<<flag<<endl;
    return 0;
}  
