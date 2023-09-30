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
        string s;
        cin>>s;
        vector<int> nums;
        for(int i = 0;i<n;i++){
            if(s[i]=='*')nums.push_back(i);
        }
        if(nums.size()==0){
            cout<<0<<endl;
            continue;
        }
        int m = nums.size()/2;
        int x = nums[m],ans = 0,y = 0;
        for(int i = x-1;i>=0;i--){
            if(s[i]=='.')y++;
            else ans+=y;
        }
        y = 0;
        for(int i = x+1;i<n;i++){
            if(s[i]=='.')y++;
            else ans+=y;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
