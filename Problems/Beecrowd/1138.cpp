#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


int DP[10][10][2][2];
string s;
const int M = 1e6;
const lli mod = 986444681;
vector<lli> fact(M+1, 1), inv(M+1, 1), invfact(M+1, 1);
lli ncr(lli n, lli r){
	if(r < 0 || r > n) return 0;
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
void calc(){
   	for(int i = 2; i <= M; ++i){
		fact[i] = (lli)fact[i-1] * i % mod;
		inv[i] = mod - (lli)inv[mod % i] * (mod / i) % mod;
		invfact[i] = (lli)invfact[i-1] * inv[i] % mod;
	}
}

int binpow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a);
        a*=a;
        b>>=1;
    }
    return x;
}

int getC(int idx,int f){
    int x =s.size()-idx;
    int ans = 0;
    if(f)
        x--;
    for(int i =1;i<=x;i++){
        ans+=ncr(i,x)*binpow(9,x-i);
    }
    if(f)
        ans*=9,ans++;
    return ans;
}

int getAns(int idx,int number ,bool f = false,bool zero = true){
    if(idx == s.size()){
        return 0;
    }
    int &x = DP[idx][number][f][zero];
    if(x!=-1)return x;
    int ans = 0;
    int LIM = 9;
    if(!f)LIM = s[idx]-'0';
    for(int i = 0;i<=LIM;i++){
        if(i==number)ans++;
        if(i==LIM && !f)
            getAns(idx+1,number,f,i==0 && zero?1:0);
        else 
            getAns(idx+1,number,!f,i==0&& zero?1:0);
        if(!zero || i)
            ans+=getC(int idx,zero);
    }
    return x = ans;
}

int solve(int x,int number){
    string s = to_string(x);
    return getAns(0,number);
}

signed main(){__
    int l,r;
    while(1){
        cin>>l>>r;
        if(!l && !r)return ;
        vector<int> a,b;
        a = solve(r);
        b = solve(l-1);
        for(int i = 0;i<=9;i++)
            cout<<a[i]-b[i]<<" ";
        cout<<endl;
    }
    return 0;
}