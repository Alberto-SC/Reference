#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t,n;
    cin>>t;;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int idx = -1,mx = -1;
        int even = 0;
        for(int i = 0;i<n;i+=2){
            if(i+1<n && nums[i+1]>nums[i]){
                if(nums[i+1]-nums[i]>mx){
                    mx = nums[i+1]-nums[i];
                    idx = i+1;
                }
            }
            if(i-1>=0 && nums[i-1]>nums[i]){
                if(nums[i-1]-nums[i]>mx){
                    mx = nums[i-1]-nums[i];
                    idx = i-1;
                }
            }
            even+=nums[i];
        }
        if(idx== -1){
            cout<<even<<endl;
            continue;
        }
        int diff1 = 0,diff2 = 0,diff3 = 0,diff4 = 0;
        int ans = 0;
        if(idx-1>=0 && nums[idx]-nums[idx-1] == mx){
            int last = mx;
            diff1 = mx;
            int i = idx+2;
            while(1){
                if(i>=n)break; 
                diff1+= nums[i]-nums[i-1];
                // if(diff1>last)last = diff1;
                // else break;
                i+=2;
            }
            i = idx-2;
            diff2 = mx;
            last = mx;
            while(1){
                if(i<1) break; 
                diff2+= nums[i]-nums[i-1];
                i-=2;
                // if(diff2>last)last = diff2;
                // else break;
            }
        }
        if(idx+1<n && nums[idx]-nums[idx+1] == mx){
            int last = mx;
            diff3 = mx;
            int i = idx+2;
            while(1){
                if(i>=n)break; 
                diff3+= nums[i]-nums[i+1];
                // if(diff3>last)last = diff3;
                // else break;
                i+=2;
            }
            i = idx-2;
            diff4 = mx;
            last = mx;
            while(1){
                if(i<0) break; 
                diff4+= nums[i]-nums[i+1];
                // if(diff4>last)last = diff4;
                // else break;
                i-=2;
            }
        }
        // cout<<even<<endl;
        // cout<<diff1<<" "<<diff2<<" "<<diff3<<" "<<diff4<<endl;
        cout<<even+max({diff1,diff2,diff3,diff4})<<endl;
    }
    return 0;
}