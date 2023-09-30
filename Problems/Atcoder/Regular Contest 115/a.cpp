#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    cin>>n>>m;
    vector<string> nums(n);
    for(auto &c:nums)cin>>c;
    int e = 0,o = 0;
    for(int i = 0;i<n;i++){
        int cont = 0;
        for(int j = 0;j<m;j++)
            cont+= nums[i][j]=='1';
        
        if(cont%2)e++;
        else o++;
    }
    cout<<e*o<<endl;
    return 0;
}  
