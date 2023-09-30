#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,p;
    cin>>T;
    while(T--){
        cin>>n>>p;
        vector<int> nums(n);
        map<int,int>mp;
        for(auto &c:nums)cin>>c,mp[c]++;
        if(n ==1){
            if(nums.back()!=2)
                cout<<p-1<<endl;
            else cout<<p-2<<endl;
            continue;
        }
        int x = nums.back();
        if(mp.count(p-1) && mp[p-1] == n-1 && x ==2){
            cout<<p-2<<endl;
            continue;
        }
        int idx =n-2;

        int last= -1;
        for(int i = x;i>=max(0ll,x-107);i--){
            if(mp.count(i)==0){
                last = i;
                break;
            }
        }
        if(last ==-1){
            int last2 = x;
            for(int i = p-1;i>=max(0ll,p-108);i--){
                if(mp.count(i)==0){
                    last2 = i;
                    break;
                }
            }
            cout<<last2-x<<endl;
        }
        else {
            while(idx>= 0 && nums[idx]==p-1){
                idx--;
            }
            if(idx>=0)
                mp[nums[idx]+1]++;
            
            // cout<<idx<<" "<<nums[idx]<<endl;
            last = 0;
            for(int i = x;i>=max(0ll,x-107);i--){
                if(mp.count(i)==0){
                    last = i;
                    break;
                }
            }
            int ans = p-x;
            ans+=last;
            cout<<ans<<endl;
        }
    }
    return 0;
}

