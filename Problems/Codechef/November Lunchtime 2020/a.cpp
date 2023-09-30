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
        for(auto &c:nums)cin>>c;
        int gas = 0;
        int cont = 0;
        for(int i = 0;i<n;i++){
            if(gas<0)break;
            gas+=nums[i];
            gas--;
            cont++;
        }
        cont+= gas;
        cout<<cont<<endl;
    }
    return 0;
}  

