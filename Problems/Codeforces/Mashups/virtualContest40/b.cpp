#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int l = 0,r = n-1,totalA=0 ,totalB = 0,turn = 0,lastA = 0,lastB = 0;
        while(1){
            if(turn%2==0){
                lastA = 0;
                while(l<=r){
                    totalA+=nums[l];
                    lastA+=nums[l];
                    l++;
                    if(lastA>lastB)break;
                }
            }
            else{
                lastB = 0;
                while(r>=l){
                    totalB+=nums[r];
                    lastB+=nums[r];
                    r--;
                    if(lastB>lastA)break;
                }
            }
            turn++;
            if(r<l)break;
        }
        cout<<turn<<" "<<totalA<<" "<<totalB<<endl;
    }
    return 0;
}  
