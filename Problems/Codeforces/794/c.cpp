#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int mod(int a,int b){
    return (((a%b)+b)%b);
}

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        map<int,int> mp;
        for(auto &c:nums)cin>>c,mp[c]++;
        if(n&1){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag = true;
        for(auto c:mp){
            if(c.second>n/2)flag = false;
        }
        if(flag){
            sort(nums.begin(),nums.end());
            int l = 0,r = n/2;
            vector<int> res;
            for(int i = 0;i<n;i++){
                if(i&1)res.push_back(nums[r++]);
                else res.push_back(nums[l++]);
            }
            for(int i = 0;i<n;i++){
                if(res[(i+1)%n]>res[i] != res[(((i-1)%n)+n)%n]>res[i])flag = false;
            }
            if(flag){
                cout<<"YES"<<endl;
                for(auto c:res)cout<<c<<" ";
                cout<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
