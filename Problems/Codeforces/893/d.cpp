#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

#define ll long long
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { 
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};


signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;

        string s;
        cin>>s;

        vector<vector<int>> pref0(k+1,vector<int>(n+1,0)),  pref1(k+1,vector<int>(n+1,0)),suff1(k+1,vector<int>(n+1,0));

        for(int i = 0;i<=k;i++){
            for(int j = n-1;j>=0;j--){
                if(s[j]== '0')
                    pref0[i][j] = pref0[i][j+1]+1; 
                else if(i)
                    pref0[i][j] = 1+pref0[i-1][j+1];
                else 
                    pref0[i][j] = 0;

                if(s[j]== '1')
                    pref1[i][j] = pref1[i][j+1]+1; 
                else  if(i)
                    pref1[i][j] = 1+pref1[i-1][j+1];
                else 
                    pref1[i][j] = 0;
            }
        }


        for(int i = 0;i<=k;i++){
            for(int j = 0;j<n;j++){
                if(s[j]== '1')
                    suff1[i][j] = j-1>=0? suff1[i][j-1]+1:1; 
                else if(i)
                    suff1[i][j] = j-1>=0? suff1[i-1][j-1]+1:1;
                else 
                    suff1[i][j] = 0;
            }
        }

        vector<vector<int>>  pref1Mx(k+1,vector<int>(n+1,0)) , suff1Mx(k+1,vector<int>(n+1,0));
        for(int i = 0;i<=k;i++){
            for(int j = n-1;j>=0;j--){
                if(j == n-1)
                    pref1Mx[i][j] = pref1[i][j]; 
                else    
                    pref1Mx[i][j] = max(pref1Mx[i][j+1],pref1[i][j]);
            }
        }

        for(int i = 0;i<=k;i++){
            for(int j = 0;j<n;j++){
                if(j== 0)
                    suff1Mx[i][j] = suff1[i][j];
                else    
                    suff1Mx[i][j] = max(suff1Mx[i][j-1],suff1[i][j]);
            }
        }



        vector<int> ans(n);

        int mx = 0;
        int l0 = 0,l1 = 0;
        map<int,int>mp;
        for(int i = 0;i<=k;i++){
            for(int j = 0;j<n;j++){
                int x = pref0[i][j];
                int y = max(k-i>= 0?pref1Mx[k-i][j+x]:0,j-1>=0 && k-i>= 0?suff1Mx[k-i][j-1]:0);

                mp[x] = max(mp[x],y);
            }
        }
        vector<pair<int,int>> v;
        for(auto c:mp){
            v.push_back(c);
        }

        LineContainer L;
        for(auto c:v){
            L.add(c.first,c.second);
        }

        int id = 0;
        for(int i = 1;i<=n;i++){
            ans[i-1] = L.query(i);
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    
    return 0;
}

