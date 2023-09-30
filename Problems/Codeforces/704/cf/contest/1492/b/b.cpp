#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        vector<int> pos(n+1);
        for(int i = 0;i<n;i++){
            cin>>nums[i];
            pos[nums[i]] = i;
        }
        vector<int> ans;
        int r = n;
        for(int i = n;i>=1;i--){
            for(int j = pos[i];j<r;j++)
                ans.push_back(nums[j]);
            r = pos[i];
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
