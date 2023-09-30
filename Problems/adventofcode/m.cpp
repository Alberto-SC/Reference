#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

inline lli normalize(lli x, lli mod) { x %= mod; if (x < 0) x += mod; return x; }
vector<lli> a; 
vector<lli> n;
lli LCM;
lli gcd(lli a,lli b,lli &x,lli &y){
	if(b==0) {x = 1; y = 0; return a;}
	lli r = gcd(b, a%b, y, x);
	y -= a/b*x;
	return r;
}
lli lcm(lli a,lli b){
    return b*(a/__gcd(a,b));
}
lli CRT(lli &ans){
    lli t =a.size();
    ans = a[0];
    LCM = n[0];
    for(lli i = 1; i < t; i++){
        lli x1,d= gcd(LCM, n[i],x1,d);
        if((a[i] - ans) % d != 0) return 0;
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * LCM, LCM * n[i] / d);
        LCM = lcm(LCM, n[i]);
    }
    return 1;
}

int main(){
    string s;
    cin>>s;
    getline(cin,s);
    getline(cin, s);
	istringstream in(s);
	vector<string> nums;
	string w;
	while(getline(in, w, ',')){
		nums.push_back(w);
    }
    lli remaind  = -1;
    for(auto c:nums){
        remaind++;
        if(c =="x")continue;
        else {
            lli x = stoi(c);
            // cout<<x<<endl;
            if(remaind == 0)a.push_back(0);
            else{
                lli z = x-remaind;
                z%=x;
                if(z<0)z+=x;
                a.push_back(z);
            }
            n.push_back(x);
        }    
    }
    lli sz = a.size();
    for(lli i = 0;i<sz;i++)
        cout<<a[i]<<" "<<n[i]<<endl;
    lli ans;
    CRT(ans);
    cout<<ans<<endl;
    return 0;
}