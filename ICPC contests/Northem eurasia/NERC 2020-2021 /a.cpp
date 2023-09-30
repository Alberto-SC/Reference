#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int inf = 1000000000;
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> nums2;
        for(int i = 1;i<n;i++)
            nums2.push_back(min(nums[i],nums[i-1]));

        for(auto c:nums2)
            cout<<c<<" ";
        cout<<endl;
        cout<<nums2.size()<<endl;
        vector<int> t2(n+1,inf);
        t2[0] = -1;
        for(auto c:nums2){
            int idx = upper_bound(t2.begin(),t2.end(),c)-t2.begin();
            t2[idx] = c;
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(t2[i]== inf)break;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}  

