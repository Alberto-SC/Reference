#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long double ld;
int main(){__
	int t= 1,n,x,m;
    ld p;
    cin>>t;
    cout<<fixed<<setprecision(10);
    while(t--){
        cin>>n>>m;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        vector<bool> suff(n);
        for(int i = n-1;i>=0;i--){
            if(nums[i]== copy[i])suff[i]=1;
            else break;
        }
        for(int i = n-1;i>=0;i--)
            if(suff[i]== 0){suff[i]= 1;break;}
        ld ans = 1;
        for(int i = 0;i<m;i++){
            cin>>x>>p;
            x--;
            if(suff[x])
                ans*= (1-p);
        }
        if(copy == nums){
            cout<<1.0<<endl;
            continue;
        }
        ld res = 1.0-ans;
        cout<<res<<endl;
    }
    return 0;
}  

