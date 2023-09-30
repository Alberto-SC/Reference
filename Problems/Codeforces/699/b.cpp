#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        nums.push_back(1e9);
        int last = 0;
        bool nou = false;
        while(k){
            bool flag = false;
            for(int i = 0;i<n;i++){
                if(nums[i]<nums[i+1]){
                    nums[i]++;
                    last = i+1;
                    if(i ==n-1)flag = true;
                    break;
                }
            }
            if(flag){
                nou = true;
                break;
            }
            k--;
        }
        if(nou)cout<<-1<<endl;
        else
        cout<<last<<endl;
    }
    return 0;
}  

