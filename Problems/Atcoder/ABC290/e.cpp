#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    
    int total = 0;
    for(int i = 1;i<=n;i++)
        total+= (i/2)* ((n-i)+1);
    

    vector<int> p[n+1];
    vector<int> s[n+1];
    vector<int> ss[n+1];
    for(int i = 0;i<n;i++){
        p[nums[i]].push_back(i+1);
        s[nums[i]].push_back(n-i);
    }
    for(int i = 1;i<=n;i++){
        ss[i].resize(s[i].size()+1);
        if(p[i].size()<=1)continue;

        for(int j = s[i].size()-1;j>=0;j--){
            ss[i][j] = ss[i][j+1]+s[i][j];
        }
    }
    for(auto &var : nums)
    {
        cin>>var;
    }
    //cout<<total<<endl;
    for(int i = 1;i<=n;i++){
        int M = p[i].size();
        if(M<=1)continue;
        
        for(int j= 0;j<M;j++){
            int nxt = lower_bound(s[i].begin()+j+1,s[i].end(),p[i][j],greater<int>())-s[i].begin();
            
            total-= p[i][j]*(nxt-j-1);
            if(nxt<M)
                total-=ss[i][nxt];

            //cout<<nxt<<" "<<ss[i][nxt]<<" "<<(nxt-j-1)<<endl;
        }
    }

    cout<<total<<endl;


    return 0;
}
