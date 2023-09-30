#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

struct ANS{
    int i,j,x;
};

signed main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        if(s%n){
            cout<<-1<<endl;
            continue;
        }
        s/=n;
        vector<ANS> ans;
        set<pair<int,int>> st;
        int need = 0;
        vector<int> pos;
        for(int i = 1;i<n;i++){
            if(nums[i]%(i+1)){
                int x = (i+1)-(nums[i]%(i+1));
                ans.push_back({1,i+1,x});
                nums[0]-=x;
                nums[i]+=x;
            }   
            ans.push_back({i+1,1,nums[i]/(i+1)});
            nums[0]+=(i+1)*(nums[i]/(i+1));
            nums[i]-=(i+1)*(nums[i]/(i+1));
        }

        for(int i= 1;i<n;i++){
            if(nums[i]!=s){
                ans.push_back({1,i+1,s-nums[i]});
            }
        }
        cout<<ans.size()<<endl;
        for(auto c:ans)
            cout<<c.i<<" "<<c.j<<" "<<c.x<<endl;
        
    }
}