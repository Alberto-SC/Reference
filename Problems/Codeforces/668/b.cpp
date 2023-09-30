  #include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int first = -1;
        lli ans = 0,carry = 0;
        for(int i = 0;i<n;){
            if(nums[i]<=0){i++;continue;}
            int j = i;
            if(nums[i]>0){
              lli sum = 0;
              carry+=nums[i];
              if(first== -1)first = i;
              j++;
              while(j<n&& nums[j]<=0){sum+=abs(nums[j]);j++;}
              if(sum>carry)ans+=sum-carry,carry = 0;
              else {
                carry-=sum;
              }
            }
            i = j;
        }
        for(int i = 0;i<first;i++)ans+=abs(nums[i]);
        cout<<ans<<endl;
    }
    return 0;
}

