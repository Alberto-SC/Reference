#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int lli;
vector<lli> st;
lli n;

void update(lli pos,lli val ,lli v = 1, lli sl = 0, lli sr = n-1){
    if(sl == sr){
        st[v] = val;
	}
    else {
        lli mid = (sl+sr)>>1;
        if(pos<=mid)
            update(pos,val,v<<1,sl,mid);
        else 
            update(pos,val,v<<1|1,mid+1,sr);
        st[v]= st[v<<1]+st[v<<1|1];
    }
}

lli query(lli l,lli r,lli v = 1,lli sl = 0,lli sr = n-1){
    if(l>sr || r<sl ||sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    lli mid = (sl+sr)>>1;
    return query(l,r,v<<1,sl,mid)+query(l,r,v<<1|1,mid+1,sr);
}

int main(){__
	lli t; cin >> t;
	while(t--){
		cin >> n;
		vector<lli> cards(n);
		for(auto &x:cards) cin >> x;
		st.assign((n+1)*4,0);
		vector<lli> idx(n+1);
		for(lli i=0; i<n; i++){
			idx[cards[i]] = i;
			//cout << cards[i] << "=" << i << endl;
			update(i, cards[i]);
		}

		//from pos 0 to 1
		lli tar = idx[1];
		lli sum = 0;
		// cout << "tar=" << tar << endl;
		// cout << query(0,tar-1) << " vs " << query(tar,n-1) << endl; 
		sum += min(query(0ll,tar-1), query(tar,n-1));
		update(tar, 0);
		
		for(lli i=2; i<=n; i++){
			if(tar > idx[i]){
				sum += min( query(min(tar,n-1),n-1)+query(0ll,idx[i]-1), query(idx[i],tar));
			}else{
				sum += min( query(tar, idx[i]-1), query(0ll, max(0ll,tar))+query(idx[i],n-1));
			}
			tar = idx[i];
			update(tar,0ll);
		}

		cout << sum << endl;
		
	}

	return 0;
}