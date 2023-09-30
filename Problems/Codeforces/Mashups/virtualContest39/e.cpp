#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    vector<int> f;
    f.push_back(2);
    f.push_back(3);
    int mx = 1e18;
    while(1){
        f.push_back(f[f.size()-1]+f[f.size()-2]);
        if(f.back()>=mx)break;
    }
    cin>>n;
    int idx = lower_bound(f.begin(),f.end(),n)-f.begin();
    if(f[idx]==n)idx++;
    cout<<idx<<endl;
    return 0;
}  
