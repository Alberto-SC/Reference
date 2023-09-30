#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int cont = 0;
        for(int i = 0;i<n; ){
            int j = i;
            while(j<n && nums[i]== nums[j]){
                j++;
            }
            if(i ==0  &&j<n && nums[j]>nums[i])cont++;
            else if(j == n && i && nums[i-1]>nums[i])cont++;
            else if(j <n && i && nums[i-1]>nums[i] && nums[j]>nums[i])cont++; 
            else if(i ==0 && j ==n)cont++;
            i = j;
        }
        if(cont==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}