#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums[n+1];
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            nums[x].push_back(i);
        }
        int ans = n;
        for(int i = 0;i<=n;i++){
            int cont = 0;
            for(int j = 1;j<nums[i].size();j++){
                if(nums[i][j]!= nums[i][j-1]+1)
                    cont++;
            }
            if(nums[i].size() && nums[i][0]>0)cont++;
            if(nums[i].size() && nums[i].back()<n-1)cont++;
            if(nums[i].size())ans = min(cont,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}  

