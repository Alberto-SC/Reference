#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0L);
using lli = int64_t;
using comp = complex<long double>;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
#define printc(A)for(auto c:A)cout<<c.real()<<" ";cout<<endl;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
typedef vector<comp> vec;
 
int nearestPowerOfTwo(int n){
	int ans = 1;
	while(ans < n) ans <<= 1;
	return ans;
}
 
lli powerMod(lli b, lli e, lli m){
	lli ans = 1;
	e %= m-1;
	if(e < 0) e += m-1;
	while(e){
		if(e & 1) ans = ans * b % m;
		e >>= 1;
		b = b * b % m;
	}
	return ans;
}
 
template<int p, int g>
void ntt(vector<int> & X, int inv){
	int n = X.size();
	for(int i = 1, j = 0; i < n - 1; ++i){
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j) swap(X[i], X[j]);
	}
	vector<lli> wp(n>>1, 1);
	for(int k = 1; k < n; k <<= 1){
		lli wk = powerMod(g, inv * (p - 1) / (k<<1), p);
		for(int j = 1; j < k; ++j)
			wp[j] = wp[j - 1] * wk % p;
		for(int i = 0; i < n; i += k << 1){
			for(int j = 0; j < k; ++j){
				int u = X[i + j], v = X[i + j + k] * wp[j] % p;
				X[i + j] = u + v < p ? u + v : u + v - p;
				X[i + j + k] = u - v < 0 ? u - v + p : u - v;
			}
		}
	}
	if(inv == -1){
		lli nrev = powerMod(n, p - 2, p);
		for(int i = 0; i < n; ++i)
			X[i] = X[i] * nrev % p;
	}
}
 
template<int p, int g>
void mult(vector<int> &A, vector<int> &B){
	int sz = A.size() + B.size() - 1;
	int size = nearestPowerOfTwo(sz);
	A.resize(size), B.resize(size);
	ntt<p, g>(A, 1), ntt<p, g>(B, 1);
	for(int i = 0; i < size; i++)
		A[i] = (lli)A[i] * B[i] % p;
	ntt<p, g>(A, -1);
	A.resize(sz);
	// return A;
}
 
int main(){
    lli n,m;
    std::clock_t start;
	double duration;
    // start = std::clock();
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vector<char>alpha = {'a','b'};
    vector<int> ans(n-m+1);
    for(char c:alpha){
        vector<int> X(n), Y(m);
        for(int i = 0; i < n; i++) s[i]== c?X[i] = 1:X[i] = 0;
        for(int i = 0; i < m; i++) t[i]== c?Y[i] = 1:Y[i] = 0;
        reverse(Y.begin(),Y.end());
        mult<998244353, 3>(X, Y);
        for(int i = 0;i<n-m+1;i++)
            ans[i] += X[i+m-1];
    }
    // print(ans)
    vector<vector<lli>> final(m+1);
    int cont = 0;
    for(int i = 0;i<ans.size();i++){
        final[m-ans[i]].push_back(i+1);
    }
    for(lli i = 0;i<=m;i++){
        cout<<i<<": ";
        for(auto d:final[i])cout<<d<<" ";
        cout<<endl;
    }
    // duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    // cout << "\n" << duration << "\n";
    return 0;
}