#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
vector<int> nums;
map<int,int> mp;
set<pair<int,int>>s;
int n;
int divide(int k,int start){
    // cout<<k<<endl;
    int ans = 0;
    int res = 0;
    if(start == n)return 0;
    if(k == 0)return 0;
    if(k == 1){
        s.clear();
        mp.clear();
        for(int j = start;j<n;j++){
            mp[nums[j]]++;  
            int frec = mp[nums[j]];
            s.erase({frec-1,nums[j]});
            s.insert({frec,nums[j]});
        }
        set<pair<int,int>>::iterator it = s.end();
        it--;
        ans += it->y - s.begin()->second;
        return ans;
    }
    for(int i = start;i<n;i++){
        s.clear();
        mp.clear();
        ans = 0;
        for(int j = start;j<=i;j++){
            // cout<<"PUTO"<<endl;
            mp[nums[j]]++;  
            int frec = mp[nums[j]];
            s.erase({frec-1,nums[j]});
            s.insert({frec,nums[j]});
        }
        set<pair<int,int>>::iterator it = s.end();
        it--;
        ans += it->y - s.begin()->second;
        // cout<<"ANS "<<i<<" "<<ans<<endl;
        // if(i == n-1){cout<<"END "<<ans<<endl;return ans;}
        int ans2 = divide(k-1,i+1);
        // ans +=divide(k-1,i+1);
        // cout<<"FINAL "<<ans2<<endl;
        res = max(ans+ans2,res);
        // cout<<"HI"<<endl;
    }
    return res;
}
int main(){
    int k;
    cin>>n>>k;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    int mx = -100;
    for(int i = 1;i<=k;i++){
        // cout<<"k = "<<i<<endl;
        int res = divide(i,0);
        mx = max(mx,res);
        // cout<<res<<endl;
    }
    cout<<mx<<endl;
    return 0;
}