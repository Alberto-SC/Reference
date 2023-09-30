#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int c = n;
        vector<vector<int>> pos(n+1); 
        for(int i = 0;i<n;i++){
            pos[nums[i]].push_back(i);
        }   
        for(int i = 0;i<=n;i++)
            reverse(pos[i].begin(),pos[i].end());
        int lastidx = 0;
        vector<int> ans;
        while(1){
            int idxmx = 0,mx = 0;
            for(int i = 0;i<=n;i++){
                bool flag = false;
                while(pos[i].size()&& pos[i].back()<lastidx)pos[i].pop_back(),c--;
                while(pos[i].size() && pos[i].back()<idxmx){
                    pos[i].pop_back();
                    c--;
                    flag = true;
                }
                if(pos[i].size()==0 && !flag){
                    mx = i;
                    break;
                }
                else if(!flag){
                    idxmx = max(idxmx,pos[i].back());
                    pos[i].pop_back();
                    c--;
                }
            }
            if(mx==0){
                for(int i =1;i<=n;i++){
                    for(auto c:pos[i]){
                        if(c>=lastidx)ans.push_back(0);
                    }
                }
                break;
            }
            else ans.push_back(mx);
            lastidx = idxmx;
        }
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;

}