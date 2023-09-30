#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    vector<int> _all;
    for(int i = 1;i<=100000;i++){
        if(i%3 && i%10 != 3)
            _all.push_back(i);
    }
    cin>>t;
    while(t--){
        cin>>n;
        cout<<_all[n-1]<<endl;
    }
    return 0;
}  
