#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);


bool check(int x,string &s,string &t,vector<int> &nums){
    int n = s.size();
    set<int> st;
    for(int i = 0;i<=x;i++)
        st.insert(nums[i]-1);
    int idx =0;
    for(int i = 0;i<n;i++){
        if(st.count(i))continue;
        if(s[i]== t[idx]){idx++;}
        if(idx==t.size())break;
    }
    if(idx == t.size())return true;
    return false;
}

signed main(){__
    int t = 1,n;
    while(t--){
        string s,t;
        cin>>s>>t;
        n = s.size();
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int l= -1 ,r = n-1;
        while(l+1<r){
            int m = (l+r)>>1;
            if(check(m,s,t,nums))
                l = m;
            else 
                r = m;
        }
        cout<<l+1<<endl;
    }
}