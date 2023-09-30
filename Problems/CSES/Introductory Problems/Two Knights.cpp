#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){__
    int n;
    cin>>n;
    vector<int> ans = {0,0,6,28,96};
    for(int i = 5;i<=n;i++){
        // ans[i] = ans[i-1];
        ans.push_back(ans[i-1]);
        ans[i] += 4*((i*i)-3);
        ans[i] += 3*((i*i)-2);
        ans[i] += (i-4)*2*((i*i)-4);
        ans[i] -= (((i*2)-1)*(i*2))/2;
        ans[i] += 2;
    }
    for(int i =1;i<=n;i++)
        cout<<ans[i]<<endl;
    return 0;
}