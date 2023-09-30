#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int INF = 1000000000;
int main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> lis[n+1];
        vector<int> ans(n);
        for(int k = 1;k<=n;k++){
            for(int i = 1;i<=n;i++){
                lis[i] = vector<int>(n+2);
                    lis[i][0] = -1;
                for(int j = 1;j<n+2;j++) 
                    lis[i][j] = INF;
            }

            // for(int i = 1;i<=n;i++){   
            //     for(auto c:lis[i])cout<<c<<" ";
            //     cout<<endl;
            // }
            // cout<<endl;
            int idx = 1;
            for(int i =0;i<n;i++){
                int idx2 = upper_bound(lis[idx].begin(),lis[idx].end(),nums[i])-lis[idx].begin();
                // cout<<idx2<<endl;
                if(idx2== k){if(lis[idx][idx2-1]<nums[i])lis[idx][idx2] = nums[i];idx = i+2;}
                else if(lis[idx][idx2-1]<nums[i])lis[idx][idx2] = nums[i];
            }
            // cout<<"HI"<<endl;
            int last = 1;
            int res = 0;
            bool flag = false;
            for(int i = 1;i<=n;i++){
                int idx2 = lower_bound(lis[i].begin(),lis[i].end(),INF)-lis[i].begin();
                if(idx2-1==k)flag = true,last = i,res+=idx2-1;
                // for(auto c:lis[i])cout<<c<<" ";
                // cout<<endl;
            }
            // cout<<"LAST "<<last<<endl;
            int idx2 = lower_bound(lis[last].begin(),lis[last].end(),INF)-lis[last].begin();
            // cout<<"RES: "<<res<<endl;
            if(flag)
                res-=k;
            // cout<<"RES: "<<res<<endl;
            lis[last][0] = -1;
            for(int i = 1;i<n+2;i++)
                lis[last][i] = INF;
            // for(auto c:lis[last])cout<<c<<" ";
                // cout<<endl;
            for(int i = last-1;i<n;i++){
                int idx2 = upper_bound(lis[last].begin(),lis[last].end(),nums[i])-lis[last].begin();
                if(lis[last][idx2-1]<nums[i])
                    lis[last][idx2] = nums[i];
            }
            idx2 = lower_bound(lis[last].begin(),lis[last].end(),INF)-lis[last].begin();
            res+=idx2-1;
            // cout<<idx2-1<<endl;
            // cout<<res<<endl;
            // for(auto c:lis[last])cout<<c<<" ";
            // cout<<endl;
            if(flag)
                ans[k-1] = res;
            else if(!flag && res>=k)ans[k-1] = res;
            else ans[k-1] = 0;
            // cout<<endl;
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}