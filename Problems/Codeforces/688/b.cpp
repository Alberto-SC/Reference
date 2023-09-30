#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int n;
vector<lli> nums;

int main(){
	lli t= 1;
    cin>>t;
    while(t--){
        cin>>n;
        nums.resize(n);
        for(auto &c:nums)cin>>c;
        lli mn = 0;
        for(int i = 1;i<n;i++)
            mn+= abs(nums[i]-nums[i-1]);
        lli mx = 0;
        for(int i = 0;i<n;i++){
            if(i==0)
                mx = max(mx,abs(nums[i]-nums[i+1]));
            else if(i ==n-1)
                mx = max(mx,abs(nums[i]-nums[i-1]));
            else    
                mx = max(mx,abs(nums[i]-nums[i-1])+abs(nums[i]-nums[i+1])-abs(nums[i-1]-nums[i+1]));
        }
        cout<<mn-mx<<endl;
    }
    return 0;
}  

