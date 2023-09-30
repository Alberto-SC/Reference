#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int i;
        for(i = *max_element(nums.begin(),nums.end());;i++){
            int total = 0;
            for(auto c:nums){
                total+= i-c;
            }   
            int need = (i*n)/2;
            if(total>need){
                break;
            }
        }
        cout<<i<<endl;
    }
    return 0;
}  

