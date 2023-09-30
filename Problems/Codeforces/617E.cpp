#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

// inline int gilbertOrder(int x, int y, int pow, int rotate) {
// 	if (pow == 0){
// 		return 0;
// 	}
// 	int hpow = 1 << (pow-1);
// 	int seg = (x < hpow) ? (
// 		(y < hpow) ? 0 : 3
// 	) : (
// 		(y < hpow) ? 1 : 2
// 	);
// 	seg = (seg + rotate) & 3;
// 	const int rotateDelta[4] = {3, 0, 0, 1};
// 	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
// 	int nrot = (rotate + rotateDelta[seg]) & 3;
// 	int subSquareSize = 1ll << (2*pow - 2);
// 	int ans = seg * subSquareSize;
// 	int add = gilbertOrder(nx, ny, pow-1, nrot);
// 	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
// 	return ans;
// }
 
// struct query{
// 	int l,r,id;int ord;
// 	inline void calcOrder() {
// 		ord = gilbertOrder(l, r, 21, 0);
// 	}
// };
 
// inline bool operator<(const query &a, const query &b) {
// 	return a.ord < b.ord;
// }

int block = 316;
struct query {
	int l, r, id;
	inline pair<int, int> toPair() const {
		return make_pair(l / block, ((l / block) & 1) ? -r : +r);
	}
};
 
inline bool operator<(const query &a, const query &b) {
	return a.toPair() < b.toPair();
}

int k = 0;
int total = 0;
int mp[1<<20];
void add(int x){
    total+=mp[x^k];
    mp[x]++;    
}

void rem(int x){
    mp[x]--;
    total-=mp[x^k];
}

signed main(){__
    int T = 1,n,m,l,r;
    while(T--){
        cin>>n>>m>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pref(n+1);
        for(int i = 1;i<=n;i++){kk
            pref[i] = pref[i-1]^nums[i-1];
        }
        vector<query> Q;
        for(int id = 0;id<m;id++){
            cin>>l>>r;
            l--;
            // Consider manage a range (l,r] if the problem work with prefix , this to be able to delete the contribution of  prefix_l
            Q.push_back({l,r,id});
            // if you use hilbert order 
            // Q.back().calcOrder();
        }
        sort(Q.begin(),Q.end());

        int L = 0,R = -1;
        vector<int> ans(m);
        for(int i = 0;i<m;i++){
            int l = Q[i].l;
            int r = Q[i].r;
            while(L>l){
                L--;
                add(pref[L]);
            }
            while(R<r){
                R++;
                add(pref[R]);
            }
            while(L<l){
                rem(pref[L]);
                L++;
            }
            while(R>r){
                rem(pref[R]);
                R--;
            }

            ans[Q[i].id] = total;
        }

        for(int i = 0;i<m;i++)
            cout<<ans[i]<<endl;
        cout<<endl;
    }
    return 0;
}