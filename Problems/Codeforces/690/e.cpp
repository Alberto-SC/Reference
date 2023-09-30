#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
lli ncr(lli n, lli k)  {  
    lli res = 1;  
    if(k>n)return 0;
    if (k>n-k)  
        k = n - k;  
    for (int i = 0; i < k; ++i){  
        res *= (n - i);  
        res /= (i + 1);  
    }  
    return res;  
}


int main(){__
	lli t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        lli ans = 0;
        lli last = -1;
        for(lli i = 0;i<n;i++){
            lli x = nums[i];
            lli idx = lower_bound(nums.begin(),nums.end(),x+3)-nums.begin();
            if(last!= -1){
                if(idx == last)continue;
                if(idx>last && last>i){
                    ans+= (((last-i)*((last-i)-1))/2)*(idx-last);
                    ans+= ncr(idx-last,3);
                    ans+=(((idx-last)*((idx-last)-1))/2)*(last-i);
                }
                else if(last<=i){
                    ans+= ncr(idx-i,3); 
                }
            }
            else{
                ans+= ncr(idx-i,3);
            }
            last = idx;
        }
        cout<<ans<<endl;
    }
    return 0;
}  

