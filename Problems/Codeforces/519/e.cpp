#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
struct a{
    lli x,y,diff,id;
    bool operator <(const a B){
        return diff<B.diff;
    }
};
int main(){__
	lli t= 1,n,m,u,v,x,y;
    while(t--){
        cin>>n>>m;
        vector<a> nums(n);
        for(lli i = 0;i<n;i++){
            cin>>x>>y;
            nums[i] = {x,y,x-y,i};
        }
        vector<a> copy = nums;
        sort(nums.begin(),nums.end());
        vector<lli> acx(n+1);
        vector<lli> acy(n+1);
        for(lli i = 1;i<=n;i++){
            acx[i] = acx[i-1]+nums[i-1].x;
            acy[i] = acy[i-1]+nums[i-1].y;
        }
        vector<lli> ans(n);
        for(lli i = 0;i<n;i++){
            lli sz = n-(i+1);
            ans[nums[i].id] = (sz*nums[i].x)+(acy[n]-acy[i+1]);
            ans[nums[i].id]+= (i*nums[i].y)+acx[i];
        }
        for(lli i = 0;i<m;i++){
            cin>>u>>v;
            u--,v--;
            ans[u]-= min(copy[u].x+copy[v].y,copy[u].y+copy[v].x);
            ans[v]-= min(copy[u].x+copy[v].y,copy[u].y+copy[v].x);
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

