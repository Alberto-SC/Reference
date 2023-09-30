#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,s;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pos(n+1);
        int last = n-1;
        for(int i = 0;i<n;i++)
            pos[nums[i]] = i;
        vector<int> ans;
        for(int i = n;i>=1;i--){
            int idx = pos[i];
            int cont = 0,cont1 = 0;
            while(idx!=last){        
                idx--;
                if(idx<0)idx = n-1;
                if(nums[idx]<i)cont++;
            }
            idx = pos[i];
            while(idx!=last){        
                idx++;
                if(idx==n)idx = 0;
                if(nums[idx]<i)cont1++;
            }
            if(cont1==0)cont =0;
            last = pos[i]-1;
            if(last<0)last = n-1;
            ans.push_back(cont);   
        }
        reverse(ans.begin(),ans.end());
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
}   