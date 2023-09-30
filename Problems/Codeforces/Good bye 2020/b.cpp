#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        vector<int> b(2*n+7);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++){
            b[nums[i]]++;
        }
        int ans = 0;
        bool flag = false;
        for(int i = 0;i<=2*n+1;i++){
            if(b[i]== 1)ans++;
            if(b[i]>1){flag = true;ans++;}
            if(b[i]== 0){
                if(flag)
                    ans++;
                flag = false;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}  

