#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> nums(n*m);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int need = n+m-1;
        int N = min(n,m);
        vector<vector<int>> ans(n,vector<int> (m,-1));
        int mn = 1e15,id = -1;
        for(int i = 0;i<=(n*m)-need;i++){
            int Nmn = N/2;
            int Nmx = (N-1)/2;
            int x  = nums[(i+need)-1]-nums[i];
            // cout<<Nmn<<" "<<Nmx<<" "<<x<<" "<<i<<" "<<(n*m)-(i+need)<<endl;
            if(i>=Nmn && ((n*m)-(i+need))>=Nmx && mn>x){
                // cout<<"YES"<<endl;
                mn = x;
                id = i;
            }
        }
        // cout<<mn<<" "<<id<<endl;
        if(id ==-1){
            int idx = 0;
            for(int i = 0;i<n;i++){
                for(int j= 0;j<m;j++){
                    ans[i][j] = nums[idx++];
                }
            }
        }
        else{
            int l = id;
            int r = (id+need)-1;
            int L = 0,R = (n*m)-1;
            if(n<m){
                int x = 0,y = 0;
                for(int i = 0;i<need;i++){
                    if(i&1){
                        ans[x][y] = nums[r--];
                        if(x!=n-1)
                            ans[x][y+1] = nums[R--];
                    }   
                    else{
                        ans[x][y] = nums[l++];
                        if(x!=n-1)
                            ans[x][y+1] = nums[L++];
                    }
                    if(x==n-1)y++;
                    else
                        x++;
                    
                }
            }
            else{
                // cout<<"HI"<<endl;
                int x = 0,y = 0;
                for(int i = 0;i<need;i++){
                    if(i&1){
                        ans[x][y] = nums[r--];
                        if(y!=m-1)
                            ans[x+1][y] = nums[R--];
                    }   
                    else{
                        ans[x][y] = nums[l++];
                        if(y!=m-1)
                            ans[x+1][y] = nums[L++];
                    }
                    if(y==m-1)x++;
                    else
                        y++;
                }
            }
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(ans[i][j]==-1){
                        if(L<id)ans[i][j] = nums[L++];
                        else ans[i][j] = nums[R--];
                    }
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}