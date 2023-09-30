#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
// #define int long long 
typedef long long int lli;
signed main(){__
	int t= 1,n;
    cin>>n;
    vector<int> gcd(n+1);
    for(int i = 1;i<=n;i++){
        gcd[i] = __gcd(i,n);
    }
    vector<int> divs;
    for(int i = 1;i*i<=n;i++){
        if(n%i==0){
            divs.push_back(i);
            if(n/i!= i&& n/i!= n)
                divs.push_back(n/i);
        }
    }
    vector<int> F(n+1);
    for(auto d:divs){
        int x = 0;
        for(int i= 1;i<n;i++){
            if(d%gcd[i])continue;
            x+=gcd[i];
        }
        F[d]= x;
    }
    lli N= (lli)n*n;
    vector<int> ans(n);
    ans[0] = N;
    for(int i = 1;i<n;i++){
        int g = gcd[i];
        ans[i] = F[g];
        ans[0]-= F[g];
    }
    for(auto c:ans)cout<<c<<endl;
    return 0;
}  
