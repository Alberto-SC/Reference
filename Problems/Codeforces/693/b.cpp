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
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int odd = 0,even = 0;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            if(nums[i]&1)odd++;
            else even++;
        }
        if(sum&1)cout<<"NO"<<endl;
        else{
            int target = sum/2;
            if(target%2 ==0)cout<<"YES"<<endl;
            else if(target&1 && odd)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}  

