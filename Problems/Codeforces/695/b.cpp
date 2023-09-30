#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int original;
vector<int> hv(300007,0);

bool is_hill_valley(vector<int> &nums,int idx){
    if(idx ==0 || idx ==nums.size()-1)return false;
    if(nums[idx]>nums[idx+1] && nums[idx]>nums[idx-1])return true;
    if(nums[idx]<nums[idx+1] && nums[idx]<nums[idx-1])return true;
    return false;
}

int check(vector<int> &nums,int idx){
    int cont = original;
    if(hv[idx-1] && !is_hill_valley(nums,idx-1))
        cont--;
    if(hv[idx+1] && !is_hill_valley(nums,idx+1))
        cont--;
    if(hv[idx])
        cont--;
    if(!hv[idx-1] &&is_hill_valley(nums,idx-1))
        cont++;
    if(!hv[idx+1] &&is_hill_valley(nums,idx+1))
        cont++;
    return cont;
}

int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = n+10;
        if(n == 1||n == 2)ans = 0;
        original = 0;
        hv.assign(n,0);
        for(int i = 1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])original++,hv[i] = 1;
            else if(nums[i]<nums[i-1] && nums[i]<nums[i+1])original++,hv[i]=2;
        }
        vector<int> copy = nums;
        for(int i = 1;i<n-1;i++){
            nums[i] = nums[i+1];
            ans = min(ans,check(nums,i));
            nums[i] = nums[i-1];
            ans = min(ans,check(nums,i));
            nums[i]= copy[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}  

