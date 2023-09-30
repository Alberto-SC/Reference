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
        int id1= 0,idn = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1){
                id1 = i;
            }
            else if(nums[i]==n){
                idn = i;
            }
        }
        bool f1 = true,f2 = true;
        int x = 1;
        for(int i = id1;i<id1+n;i++){
            if(nums[i%n]!=x){
                f1 = false;
            }
            x++;
        }
        x = n;
        for(int i= idn;i<idn+n;i++){
            if(nums[i%n]!=x){
                f2 = false;
            }
            x--;
        }
        if(f1 || f2 )cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}