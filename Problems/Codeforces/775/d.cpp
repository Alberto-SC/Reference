#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t = 1,n,s,c;
    cin>>t;
    while(t--){
        cin>>n>>c;
        vector<int> nums(n);
        vector<int> exist(c+1);
        for(auto &c:nums)cin>>c,exist[c]++;
        vector<int> b(c+1);
        for(int i = 0;i<n;i++)
            b[nums[i]]++;
        vector<int> ac(c+1);
        for(int i = 1;i<=c;i++)
            ac[i] = ac[i-1]+b[i];

        bool flag = true;
        for(int i = 0;i<n;i++){
            vector<int> poss;
            for(int j = 1;j*j<=nums[i];j++){
                int x = nums[i]/j;
                poss.push_back(x);
                poss.push_back(j);
            }
            sort(poss.begin(),poss.end());

            for(auto d:poss){
                int l = nums[i]/(d+1);
                int r = nums[i]/d;
                l++;
                if(ac[r]-ac[l-1] && !exist[d])flag = false;
            }
        }

        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}   