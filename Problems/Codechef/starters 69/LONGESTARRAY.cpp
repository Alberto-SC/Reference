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
        for(auto &c:nums)cin>>c;
        vector<int> bits[31];
        vector<int> pos[31];
        for(int b = 0;b<31;b++){
            bits[b].resize(n);
            for(int i = 0 ;i<n;i++){
                bits[b][i] = (nums[i]>>b)&1;
                if(i)bits[b][i]+=bits[b][i-1];
                if((nums[i]>>b)&1)
                    pos[b].push_back(i);
            }
            reverse(pos[b].begin(),pos[b].end());
        }
        int ans = -1;
        for(int i = 0;i<n;i++){
            int L = i, R = n-1;
            for(int b = 0;b<31;b++){
                if(pos[b].size() && pos[b].back()<i)pos[b].pop_back();
                if(i && bits[b][i-1]){
                    if(pos[b].size()){
                        L = max(L,pos[b].back());
                        R = min(R,n-1);
                    }
                    else R= i-1;
                }
                else{
                    if(bits[b].back()){
                        L = max(L,pos[b].back());
                        R = min(R,pos[b][0]-1);
                    }
                }
            }
            if(L<=R && R>=i){
                ans = max((R-i)+1,ans);
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}