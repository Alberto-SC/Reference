#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int solve(int bit,vector<int> v){
    if(bit==-1)return 0;
    vector<int> s;
    vector<int> t;
    for(int i =0;i<v.size();i++){
        if((v[i]>>bit)&1)s.push_back(v[i]);
        else t.push_back(v[i]);
    }
    if(s.size()==0 || t.size()== 0)return solve(bit-1,s.size()?s:t);
    return min(solve(bit-1,s),solve(bit-1,t))+(1<<bit);
}

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        cout<<solve(30,nums)<<endl;
    }
    return 0;
}