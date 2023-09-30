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
        sort(nums.begin(),nums.end());
        int mn  = nums[0];
        int cont = 1;
        for(int i= 1;i<n;i++){
            if(nums[i]== mn)cont++;
        }
        cout<<n-cont<<endl;
    }
    return 0;
}  

