#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        set<int> st;  
        for(auto &c:nums)cin>>c,st.insert(c);
        vector<int> d;
        for(int i = 0;i<n;i++){
            for(int j= i+1;j<n;j++){
                int diff = abs(nums[i]-nums[j]);
                d.push_back(diff);
            }
        }
        bool flag = true;
        for(int i = 0;i<d.size();i++){
            for(int j = i+1;j<d.size();j++){
                int gcd = __gcd(d[i],d[j]);
                if(gcd!=1)flag = false;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}