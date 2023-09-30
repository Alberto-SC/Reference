#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int ans = 0;
void solve(int &h,multiset<int> &st){
    while(st.size()){
        auto x = *st.begin();
        if(x<h){
            ans++;
            h+=x/2;
            st.erase(st.begin());
        }
        else break;
    } 
}

void f1(int h,multiset<int> st){
    ans = 0;
    solve(h,st);
    h*=2;
    solve(h,st);
    h*=2;
    solve(h,st);
    h*=3;
    solve(h,st);
}

void f2(int h,multiset<int> st){
    ans = 0;
    solve(h,st);
    h*=2;
    solve(h,st);
    h*=3;
    solve(h,st);
    h*=2;
    solve(h,st);
}

void f3(int h,multiset<int> st){
    ans = 0;
    solve(h,st);
    h*=3;
    solve(h,st);
    h*=2;
    solve(h,st);
    h*=2;
    solve(h,st);
}



signed main(){__
    int T = 1,n,h;
    cin>>T;
    while(T--){
        cin>>n>>h;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        multiset<int> st(nums.begin(),nums.end());
        int res = 0;
        f1(h,st);
        res = max(res,ans);
        f2(h,st);
        res = max(res,ans);
        f3(h,st);
        res = max(res,ans);
        cout<<res<<endl;    
    }
    return 0;
}