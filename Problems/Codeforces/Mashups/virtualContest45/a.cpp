#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        vector<int> nums(5);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        if(s%5==0 && s)
            cout<<s/5<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}  
