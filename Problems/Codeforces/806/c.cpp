#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++){
            int x; 
            cin>>x;
            string s;
            cin>>s;
            for(int j = 0;j<x;j++){
                if(s[j]=='D'){
                    nums[i]++;
                    if(nums[i]==10)nums[i] = 0;
                }
                else{
                    nums[i]--;
                    if(nums[i]==-1)nums[i] = 9;
                }
            }
        }
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;

    }
    return 0;
}  
