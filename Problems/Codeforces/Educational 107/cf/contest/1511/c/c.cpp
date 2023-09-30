#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,q,c;
    while(t--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pos(51,-1);
        for(int i =0 ;i<n;i++){
            if(pos[nums[i]]==-1)
                pos[nums[i]] = i+1;
        }
        for(int i = 0;i<q;i++){
            cin>>c;
            cout<<pos[c]<<" ";
            for(int j = 1;j<=50;j++){
                if(j ==c)continue;
                if(pos[j]<pos[c])pos[j]++;
            }
            pos[c] = 1;
        }
    }
    return 0;
}  
