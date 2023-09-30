#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<char> nums(n);
        for(auto &c:nums)cin>>c;
        vector<char> nw(n);
        while(m--){
            if(nums[1]=='1'|| nums[0]=='1')nw[0] = '1';
            else nw[0] = '0';
            if(nums[n-2]=='1'|| nums[n-1] == '1')nw[n-1]='1';
            else nw[n-1] = '0';
            for(int i = 0;i<n;i++){
                int cont = (nums[i-1]=='1')+ (nums[i+1]=='1');
                if(cont==1 || nums[i]== '1')nw[i] = '1';
                else nw[i] = '0';
                
            }
            if(nums ==nw)break;
            nums = nw;
        }
        for(auto c:nw)cout<<c;
        cout<<endl;
    }
    return 0;
}  
