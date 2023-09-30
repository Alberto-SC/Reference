#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


inline int gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0){
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int subSquareSize = 1ll << (2*pow - 2);
	int ans = seg * subSquareSize;
	int add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
 
struct query{
	int l,r,id;int ord;
	inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0);
	}
};
 
inline bool operator<(const query &a, const query &b) {
	return a.ord < b.ord;
}


signed main(){__
    int T = 1,n,w,m,l,r,k;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        n = s.size();
        cin>>w>>m;
        int x = 0;
        vector<pair<int,int>> mp(10,{-1,-1}); 
        for(int i = 0;i<w;i++){
            x+=s[i]-'0';
        }
        mp[x%9].first = 0;  
        for(int i =w;i<n;i++){
            x-=s[i-w]-'0';
            x+=s[i]-'0';
            if(mp[x%9].first==-1)mp[x%9].first = (i-w)+1 ;
            else if(mp[x%9].second==-1)mp[x%9].second = (i-w)+1;

        }
        vector<int> ac(n);
        ac[0]= s[0]-'0';
        for(int i = 1;i<n;i++){
            ac[i] = ac[i-1]+(s[i]-'0');
        }
        while(m--){
            cin>>l>>r>>k;
            l--,r--;    
            int md = ac[r]-(l?ac[l-1]:0);
            md%=9;
            pair<int,int> ans = {n+1,n+1};
            for(int i = 0;i<9;i++){
                if(mp[i].first==-1)continue;
                int need = (md*i)%9;
                if(k>need)need = k-need;
                else need = (9-need)+k;
                need%=9;
                if(need ==i){
                    if(mp[i].second!= -1)ans = min(ans,{mp[i].first,mp[i].second});
                }
                else if(need !=i && mp[need].first!=-1) { 
                    ans = min(ans,{mp[i].first,mp[need].first});
                }
            }
            if(ans.first==n+1)cout<<"-1 -1"<<endl;
            else 
                cout<<ans.first+1<<" "<<ans.second+1<<endl;
        }   
    }
    return 0;
}