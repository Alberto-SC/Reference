#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        m--;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pref(n);
        pref[0] = nums[0];
        int mn = pref[0];
        for(int i = 1;i<n;i++){
            pref[i] = pref[i-1]+nums[i];
            mn = min(mn,pref[i]);
        }
        if(pref[m]==mn){
            cout<<0<<endl;
            continue;
        }
        // for(auto c:pref){
        //     cout<<c<<" ";
        // }
        // cout<<endl;
        int ans = 0;
        int ac = 0;
        if(nums[m]>0 && m){
            ans++;
            ac+=nums[m]*2;
            pref[m]-=ac;
        }
        priority_queue<int> pq;
        for(int i= m+1;i<n;i++){
            pref[i]-=ac;
            // cout<<"I :"<<i<<" "<<ac<<" "<<pref[i]<<endl;
            if(pref[i]<pref[m]){
                int mx;
                if(pq.size()){
                    mx = -pq.top();
                    if(mx<nums[i]){
                        pq.pop();
                        if(nums[i]<0)pq.push(-nums[i]);
                    }
                    else mx = nums[i];
                }
                else mx = nums[i];
                // cout<<i<<" "<<mx<<endl;
                ans++;
                ac+=mx*2;
                pref[i]-=mx*2;
            }
            else if(nums[i]<0){
                pq.push(-nums[i]);
            }
        }
        // cout<<ans<<endl;
        while(pq.size()){
            pq.pop();
        }
        ac = 0;
        for(int i = m-1;i>=0;i--){
            if(pref[i]<pref[m]){
                bool flag = false;
                while(1){
                    if(pq.size()==0)break;
                    int mx  = pq.top();
                    pq.pop();
                    pref[m]-=2*mx;
                    ans++;
                    if(pref[m]<=pref[i]){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    ans++;
                    pref[m]-=nums[i]*2;
                }
                else if(nums[i]>0){
                    pq.push(nums[i]);
                }
            }
            else if(nums[i]>0){
                pq.push(nums[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}