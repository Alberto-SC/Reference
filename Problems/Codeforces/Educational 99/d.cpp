#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
bool sorted(vector<int> nums){
    int n = nums.size();
    for(int i = 0;i<n-1;i++){
        if(nums[i]>nums[i+1])return false;
    }
    return true;
}
int main(){__
	int t= 1,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> copy = nums;
        copy.push_back(x);
        sort(copy.begin(),copy.end());
        int idx = lower_bound(copy.begin(),copy.end(),x)-copy.begin();
        bool flag = true;
        for(int i = 0;i<idx-1;i++)
            if(i+1<n && nums[i]>nums[i+1])flag = false;

        if(!flag)cout<<-1<<endl;
        else{
            int cont = 0;
            while(x != copy.back() && !sorted(nums)){
                int idx = lower_bound(copy.begin(),copy.end(),x)-copy.begin();
                if(nums[idx] ==x){
                    while(idx<n && nums[idx]== copy[idx]){
                        idx++;
                    }
                    if(nums[idx]>x){
                        swap(nums[idx],x);
                        cont++;
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                else if(nums[idx]<x){
                    flag = false;
                    break;
                }
                else{
                    swap(nums[idx],x);
                    cont++;
                }
                if(!flag)break;
            }
            if(!flag || !sorted())cout<<-1<<endl;
            else
                cout<<cont<<endl;
        }

    }
    return 0;
}  

