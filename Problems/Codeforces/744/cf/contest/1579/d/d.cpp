#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> nums(n);
        priority_queue<pair<int,int>> p;
        for(int i = 0;i<n;i++){
            cin>>nums[i].x;
            nums[i].y = i+1;
            if(nums[i].x)
                p.push({nums[i]});
        }
        vector<pair<int,int>> ans;
        
        while(p.size()>1){
            auto a1 = p.top();
            p.pop();
            auto a2 = p.top();
            p.pop();
            ans.push_back({a1.y,a2.y});
            a1.x--,a2.x--;
            if(a1.x)p.push(a1);
            if(a2.x)p.push(a2);
        }
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c.x<<" "<<c.y<<endl;
        
    }
    return 0;
}  
