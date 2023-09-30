#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

bool check(int l,int r,vector<int> &nums){
    int len = (r-l)+1;
    if(len&1)return false;
    vector<int> b(5007);
    for(int i = l;i<=r;i++){
        b[nums[i]]++;
        if(b[nums[i]]>len/2)return false;
    }
    return true;
}

signed main(){__
    int t,n,a,b,c,d;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> V[n+1];
        for(int i = 0;i<n;i++){
            V[nums[i]].push_back(i);
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(V[i].size()==0)continue;
            int l = V[i].back()+1,r = -1;
            for(int j = 0;j<V[i].size();j++){
                if(V[i][j]==0){l = 0;break;}
                if(check(0,V[i][j]-1,nums)){l =j;break;}
            }
            for(int j = V[i].size()-1;j>=0;j--){
                if(V[i][j]==n-1){r = j;break;}
                if(check(V[i][j]+1,n-1,nums)){r = j;break;}
            }
            if(r<l)continue;
            if(l == r){
                ans = max(ans,1ll);
                continue;
            }
            int len = -1;
            for(int j = l;j<r;j++){
                if(!check(V[i][j]+1,V[i][j+1]-1,nums)){
                    len = j-l;
                    break;
                }
            }
            if(len ==-1)ans = max((r-l)+1,ans);
            else{
                for(int j = r;j>l;j--){
                    if(!check(V[i][j-1]+1,V[i][j]-1,nums)){
                        len = max(len,r-j);
                        break;
                    }
                }
                ans = max(len+1,ans);
            }
        }
        cout<<ans<<endl;
    }
}
