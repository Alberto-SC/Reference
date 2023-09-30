#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct q{
    int i,j,k;
};

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<vector<int>> nums(n,vector<int>(m));
        vector<int> sum(n);
        int total = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>nums[i][j];
                sum[i]+=nums[i][j];
                total+=nums[i][j];
            }
        }
        if(total%n){
            cout<<-1<<endl;
            continue;
        }

        int need = total/n;
        vector<q> ans;
        for(int i = 0;i<m;i++){
            vector<int> a,b;
            for(int j = 0;j<n;j++){
                if(sum[j]<need && !nums[j][i])a.push_back(j);
                else if(sum[j]>need && nums[j][i])b.push_back(j);
            }

            for(int j = 0;j<min(a.size(),b.size());j++){
                nums[a[j]][i] = 1;
                nums[b[j]][i] = 0;
                sum[a[j]]++;
                sum[b[j]]--;
                ans.push_back({a[j]+1,b[j]+1,i+1});
            }
        }
        cout<<ans.size()<<endl;
        for(auto c:ans){
            cout<<c.i<<" "<<c.j<<" "<<c.k<<endl;
        }
    }
    return 0;
}