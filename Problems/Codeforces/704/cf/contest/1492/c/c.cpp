
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
struct ST{
    int n;
    vector<int> st;
    ST(int n):n(n){
        st.resize(4*n,0);
    }
	inline void update(int x, int val) {
		x += n;
		st[x] = val;
		for (; x >>=1 ; st[x] = st[x<<1]+st[x<<1|1]);
	}
	inline int query(int l, int r) {
		int ans = 0;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans+=st[l];
			if (~r & 1) ans+=st[r];
		}
		return ans;
	}
};
signed main(){__
	int n,m;
    string s,t;
    cin>>n>>m;
    cin>>s>>t;
    vector<ST> st(27,ST(n));
    vector<int> idx[27];
    vector<int> f(27);
    vector<int> l(27);
    for(int i = 0;i<n;i++){
        idx[s[i]-'a'].push_back(i);
        st[s[i]-'a'].update(i,1);
    }
    
    int last = 0;
    for(int i = 1;i<m;i++)
        f[t[i]-'a']++;
    
    for(int i = 0;i<n;i++){
        if(s[i]==t[0]){
            last = i;
            l[s[i]-'a']++;
            break;
        }
        else{
            l[s[i]-'a']++;
        }
    }

    int id = 1;
    int mx = 1;
    for(int i = 1;i<n;i++){
        if(id>=m)break;
        if(s[i]!= t[id]){
            l[s[i]-'a']++;
            continue;
        }
        if(s[i]== t[id]){
            bool flag = true;
            int nxt =0;
            cout<<i<<" "<<idx[s[i]-'a'][l[s[i]-'a']]<<endl;
            // assert(l[s[i]-'a']== i);
            if(l[s[i]-'a']+1== (int)idx[s[i]-'a'].size())
                flag = false;
            else      
                nxt = idx[s[i]-'a'][l[s[i]-'a']+1];
            for(int j = 0;j<26;j++){
                if(st[j].query(nxt,n)<f[j])flag = false;
            }
            if(!flag){
                mx = max(mx,i-last);
                last = i;
                f[t[id]-'a']--;
                id++;
            }
            l[s[i]-'a']++;
        }
    }
    cout<<mx<<endl;
    return 0;
}  
