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
        int x = 0;
        for(auto &c:nums)cin>>c,x^=c;
        if(x== 0){cout<<"DRAW"<<endl;continue;}
        int cont =0;
        for(int i = 31;i>=0;i--){
            if((x>>i)&1){
                for(int j = 0;j<n;j++)
                    cont+=(nums[j]>>i)&1;
                break;
            }
        }
        if(cont%4 == 3 && (n-cont)%2==0)cout<<"LOSE"<<endl;
        else cout<<"WIN"<<endl;
    }

    return 0;
}  
