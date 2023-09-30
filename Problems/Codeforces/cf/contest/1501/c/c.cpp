#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0L);
using lli = int64_t;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
#define printc(A)for(auto c:A)cout<<c.real()<<" ";cout<<endl;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
int N = 2500007;
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
	int sz = A.size() + A.size() - 1;
	int size = nearestPowerOfTwo(sz);
	A.resize(size), B.resize(size);
	ntt<p, g>(A, 1);
	for(int i = 0; i < size; i++)
		B[i] = (lli)A[i] * A[i] % p;
	ntt<p, g>(B, -1);
	B.resize(sz);
	// return A;
}
 
int main(){__
    lli n,m;
    cin>>n;
    vector<int> nums(n);
    vector<int> f(N);
    for(auto &c:nums)cin>>c;
    vector<int> X(N);
    unordered_map<int,int> mp;
    mp.reserve(32768); 
    mp.max_load_factor(0.25); 
    for(int i = 0;i<n;i++){
        mp[nums[i]] = i;
        X[nums[i]]= 1;
        f[nums[i]]++;
    }
    int f4 = 0;
    int f2f = 0,f2s = 0;
    for(int i = 0;i<N;i++){
        if(f[i]>=4){
            f4 = i;
            break;
        }
        if(f[i]>=2){
            if(f2f){ 
                f2s = i;
                break;
            }
            else 
                f2f = i;
            
        }
    }
    if(f4){
        cout<<"YES"<<endl;
        for(int i = 0,cont = 4;i<n&&cont;i++)
            if(nums[i]== f4)cout<<i+1<<" ",cont--;
        return 0;
    }
    if(f2s){
        vector<int> ans;
        for(int i = 0,cont = 2;i<n&&cont;i++)
            if(nums[i]==f2f)ans.push_back(i+1),cont--;
        for(int i = 0,cont = 2;i<n&&cont;i++)
            if(nums[i]==f2s)ans.push_back(i+1),cont--;
        swap(ans[1],ans[2]);
        cout<<"YES"<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
        return 0;
    }
    vector<int> Y;
    mult<998244353, 3>(X, Y);

    for(int i = 0;i<N;i++)
        if(f[i])
            Y[i*2]--;
    
    for(int i = 0;i<N;i++)
        Y[i]/=2;
    int sum = 0;
    for(int i= 0;i<N;i++){
        if(Y[i]>1){
            sum = i;
            break;
        }
        if(Y[i]== 1 && (i%2 == 0) && f[i/2]>=2){
            sum = i;
            break;
        }
    }
    vector<int> used(n);
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(used[i])continue;
        if(mp.count(sum-nums[i])&& mp[sum-nums[i]]!= i && !used[mp[sum-nums[i]]]){
            ans.push_back(i+1);
            ans.push_back(mp[sum-nums[i]]+1);
            used[mp[sum-nums[i]]] = true;
        }
        if(ans.size()==4)break;
    }
    if(sum){
        cout<<"YES"<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    else 
        cout<<"NO"<<endl;

    return 0;
}