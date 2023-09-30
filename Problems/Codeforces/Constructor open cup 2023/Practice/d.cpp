
#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(2*n);
        for(int i = 0;i<2*n;i++)cin>>nums[i];

        multiset<int> s(nums.begin(),nums.end());
        
        vector<int> ans;
        while(s.size()){
            int mx = *s.rbegin();
            
            int aux = mx;
            int sum = 0;
            while(aux){
                sum+=aux%10;
                aux/=10;
            }

            s.erase(s.find(sum));
            s.erase(s.find(mx));
            ans.push_back(mx);
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}
