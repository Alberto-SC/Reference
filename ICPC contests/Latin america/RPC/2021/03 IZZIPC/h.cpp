#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,c,x;
    while(t--){
        cin>>n;
        vector<int> nums[n];
        int s =0;
        for(int i = 0;i<n;i++){
            cin>>c;
            for(int j = 0;j<c;j++)
                cin>>x,nums[i].push_back(x);
            s+=c;
            reverse(nums[i].begin(),nums[i].end());
        }

        while(s--){
            int idx = 0,mn =1e15;
            for(int i = 0;i<n;i++){
                if(nums[i].size()==0)continue;
                if(nums[i].back()<mn){
                    idx = i;
                    mn =nums[i].back();
                }
            }
            cout<<char('A'+idx);
            nums[idx].pop_back();
        }
        cout<<endl;
    }
    return 0;
}  
