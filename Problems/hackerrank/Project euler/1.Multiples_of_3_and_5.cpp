#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        n--;
        int lcm = 15;
        int x = n/3, y = n/5,z = n/15;
        int sum = 0;
        sum+=3* ((x*(x+1))/2);
        sum+=5* ((y*(y+1))/2);
        sum-=15* ((z*(z+1))/2);
        cout<<sum<<endl;
    }

    return 0;
}
