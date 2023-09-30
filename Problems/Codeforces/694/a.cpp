#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<lli> nums(n);
        lli mn = 0,mx = 0,s = 0;
        for(auto &c:nums){
            cin>>c;
            mx+= (c/x);
            if(c%x)mx++;
            s+=c;
        }
        mn = s/x;
        if(s%x)mn++;
        cout<<mn<<" "<<mx<<endl;
    }
    return 0;
}  

