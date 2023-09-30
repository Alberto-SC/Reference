#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
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
                lis[i] = vector<int>((n+1)-(i-1));
                    lis[i][0] = -1;
                for(int j = 1;j<(n+1)-(i-1);j++)
                    lis[i][j] = INF;
            }
  
            cout<<"K: "<<k<<endl;
            for(int i = 1;i<=n;i++){   
                for(auto c:lis[i])cout<<c<<" ";
                cout<<endl;
            }
            cout<<endl;
            int idx = 1;
            for(int i =0;i<n;i++){
                int idx2 = upper_bound(lis[idx].begin(),lis[idx].end(),nums[i])-lis[idx].begin();
                cout<<idx2<<endl;
                if(idx2== k){if(lis[idx][idx2-1]<nums[i])lis[idx][idx2] = nums[i];idx = i+2;}
                else lis[idx][idx2] = nums[i];
            }
            int last = 1;
            int res = 0;
            for(int i = 1;i<=n;i++){
                int idx2 = lower_bound(lis[i].begin(),lis[i].end(),INF)-lis[i].begin();
                if(idx2-1==k)last = i,res+=idx2-1;
                for(auto c:lis[i])cout<<c<<" ";
                cout<<endl;
            }
            cout<<"LAST "<<last<<endl;
            res-=k;
            lis[last][0] = -1;
            for(int i = 1;i<=(n+1)-(last-1);i++)
                lis[last][i] = INF;
            for(auto c:lis[last])cout<<c<<" ";
                cout<<endl;
            for(int i = last-1;i<n;i++){
                int idx2 = upper_bound(lis[last].begin(),lis[last].end(),nums[i])-lis[last].begin();
                if(lis[idx][idx2-1]<nums[i])
                    lis[last][idx2] = nums[i];
            }
            int idx2 = lower_bound(lis[last].begin(),lis[last].end(),INF)-lis[last].begin();
            res+=idx2-1;
            cout<<idx2-1<<endl;
            for(auto c:lis[last])cout<<c<<" ";
            cout<<endl;
            ans[k-1] = res;
            cout<<endl;
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}
