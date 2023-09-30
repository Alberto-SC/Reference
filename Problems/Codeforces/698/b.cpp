#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,d;
    cin>>t;
    while(t--){
        cin>>n>>d;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++){
            if(nums[i]>=d*10){
                cout<<"YES"<<endl;
            }
            else{
                bool flag = false;
                for(int j = 1;j<=10;j++){
                    if((d*j)%10==nums[i]%10 && d*j<=nums[i]){
                        flag = true;
                    }
                }
                if(flag)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }

    }
    return 0;
}  

