#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int gauss(int n){
    return (n*(n+1))/2;
}

int f(int p, int q, int n) {
    int ans = gauss(n) * (p/q);
    cout<<p<<" "<<q<<" "<<n<<" "<<ans<<endl;
    p %= q;
    if (p != 0) {
        int N = (p*n)/q;
        cout<<N<<endl;
        ans += n * N - f(q, p, N) + N/p;
    }
    return ans;
}

lli f(lli a, lli b, lli c, lli n){
	lli m = (a*n + b)/c;
	if(n==0 || m==0) return b/c;
	if(n==1) return b/c + (a+b)/c;
	if(a<c && b<c) return m*n - f(c, c-b-1, a, m-1);
	else return (a/c)*n*(n+1)/2 + (b/c)*(n+1) + f(a%c, b%c, c, n);
}



signed main(){__
    int t,p,q,n;
    cin>>p>>q>>n;
    int s = 0;
    int x =1;
    int g = __gcd(p,q);
    for(int i = 0;i<=q-1;i++){
        cout<<i%q<<" "<<__gcd(i,q)<<" "<<(p*i)/q<<"  "<<p*i<<endl;
        s+= (p*i)/q;
    }
    int ans = ((p-1)*(q-1)+__gcd(p,q)-1)/2;
    ans*=x;
    ans+=(x-1)*p*(q-1);
    ans+=(x-1)*p;
    cout<<s<<endl;
    cout<<ans<<endl;
    cout<<f(p/g,q/g,n)<<endl;
    int ans1 = (p* gauss(n))-(q*f(p/g,q/g,n));
    cout<<ans1<<endl;
}   