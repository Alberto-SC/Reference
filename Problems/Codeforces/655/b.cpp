#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

lli lcm(lli a,lli b){
    return b*(a/__gcd(a,b));
}
int main(){__
	int t = 1,n;
    cin>>t;
	while(t--){
		cin>>n;
        if(n%2== 0)cout<<n/2<<" "<<n/2<<endl;
        else {
            int ans = 1000000000;
            int a,b;
            for(int i = 1;i*i<=n;i++){
                if(n%i == 0){
                    int x = n/i;
                    int y = lcm(i,i*(x-1));
                    if(y<ans)a = i, b = i*(x-1);
                    ans= min(ans,y);
                    if(n/i != i){
                        int div = n/i;
                        if(div == n)continue;
                        int y = lcm(div,div*(i-1));
                        if(y<ans)a = div, b = div*(i-1);
                        ans= min(ans,y);
                    }   
                } 
            }
            cout<<a<<" "<<b<<" "<<ans<<endl;
        }
	}
    return 0;
}  