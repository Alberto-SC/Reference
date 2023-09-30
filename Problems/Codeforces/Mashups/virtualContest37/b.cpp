#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,d;
    while(t--){
        cin>>n>>m>>d;
        vector<vector<int>> nums(n,vector<int>(m));
        int g = 0;
        vector<int> v;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin>>nums[i][j],g = __gcd(nums[i][j],g),v.push_back(nums[i][j]);
        int m = v.size()/2;
        sort(v.begin(),v.end());
        int target = v[m];
        int ans = 0;
        bool flag = true;
        for(int i = 0;i<v.size();i++){
            if(abs(v[i]-target)%d)flag = false;
            ans+= abs(v[i]-target)/d;
        }
        if(flag)
            cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}  
