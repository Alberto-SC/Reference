#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;   
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int M = 1e6;
const lli mod = 998244353;
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


int main(){__
    int n,l,r,k;
    cin>>n>>k; 
    vector<pair<lli,lli>> segments;
    vector<lli> No(n);
    for(int i = 0;i<n;i++){
        cin>>l>>r;
        segments.push_back({l,r});

    }
    sort(segments.begin(),segments.end());
    multiset<int> st;
    calc();
    lli ans = 0;
    for(int i = 0;i<n;i++){
        while(!st.empty() && (*st.begin())<segments[i].first){
            st.erase(st.begin());
        }
        ans+= ncr(st.size(),k-1);
        ans%=mod;
        st.insert(segments[i].second);
    }
    cout<<ans<<endl;

    return 0;
}

