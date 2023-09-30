#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int gcd(int a,int b,int &x,int &y){
	if(b==0) {x = 1; y = 0; return a;}
	int r = gcd(b, a%b, y, x);
	y -= a/b*x;
	return r;
}
lli lcm(lli a,lli b){
    return b*(a/__gcd(a,b));
}
int inverse(int a, int m){
	int x, y ;
    // if isPrime(m)return mod_pow(a,m-2,m);
	if(gcd( a, m, x, y ) != 1) return 0;
	return (x%m + m) % m;
}
inline lli normalize(lli x, lli mod) { x %= mod; if (x < 0) x += mod; return x; }
vector<int> a; 
vector<int> n;
lli CRT(lli &ans,lli &LCM){
    int t =a.size();
    ans = a[0];
    LCM = n[0];
    for(int i = 1; i < t; i++){
        int x1,d= gcd(LCM, n[i],x1,d);
        if((a[i] - ans) % d != 0) return 0;
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * LCM, LCM * n[i] / d);
        LCM = lcm(LCM, n[i]); // you can save time by replacing above LCM * n[i] /d by LCM = LCM * n[i] / d
    }
    return 1;
}
int main(){
    int t,ai,nn,b,m;
    cin>>t;
    while(t--){
        cin>>ai>>nn>>b>>m;
        normalize(ai, nn);
        normalize(b, m);
        a.clear();
        n.clear();
        a.push_back(ai);
        a.push_back(b);
        n.push_back(nn);
        n.push_back(m);
        lli ans,LCM;
        if(!CRT(ans,LCM))cout<<"no solution"<<endl;
        else cout<<ans<<" "<<LCM<<endl;
    }
}