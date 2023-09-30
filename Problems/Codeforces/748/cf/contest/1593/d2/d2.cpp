#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int ans = 1,target = n/2;
        map<int,int> mp;
        for(auto c:nums)mp[c]++;
        for(int i = 0;i<n;i++){
            vector<int> diff;
            for(int j = i;j<n;j++){
                diff.push_back(nums[j]-nums[i]);
            }
            set<int> divs;
            for(auto c:diff){
                for(int j = 1;j*j<=c;j++){
                    if(c%j==0){
                        divs.insert(j);
                        if(c/j!= j)divs.insert(c/j);
                    }
                }
            }
            for(auto c:divs){
                int cont = 0;
                for(auto d:diff){
                    if(d%c==0)cont++;
                }
                if(cont>=target)
                    ans = max(ans,c);
            }
        }
        for(auto c:mp){
            if(c.second>=target)ans = -1;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
