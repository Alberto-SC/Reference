#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
vector<int> p_function(const string& v){
    int n = v.size();
    vector<int> p(n);
    for(int i = 1; i < n; i++){
        int j = p[i - 1];
        while(j > 0 && v[j] != v[i]){
            j = p[j - 1];
        }
        if(v[j] == v[i])
            j++;
        p[i] = j;   
    }
    return p;
}
vector<bool> Match(507);

vector<int>  match(const string& s, const string& pat) {
	int n = pat.size();
	int m = s.size();
	if(m<n){
		return {};
	}
	string match = pat+"#"+s;
	vector<int> kmp =p_function(match);
    vector<int> idx;
	for(int i = n; i < m + n + 1; i++){   
		if(kmp[i] == n){   
            idx.push_back((i-n)+1-(n+1));
            Match[idx.back()] = true;
        }
    }
    return idx;
}

pair<int,int> dp[507][507];

int n,M,m;
const int INF = 1e9;
vector<int> Index;
pair<int,int> solve(int idx,int last){
    if(idx == n && last+1 ==M)return {0,1};
    else if(idx ==n && last+1 !=M)return {INF,0};
    auto &x = dp[idx][last];
    if(x.first!=-1)return x;
    pair<int,int> ans;
    if((Index[last]+m)-1<idx){return {INF,0};}
    if(Match[idx]){
        auto x = solve(idx+1,last);
        int nxt = last;
        while(nxt<M && Index[nxt]<=(idx+m)-1){
            nxt++;
        }
        auto  y = solve(Index[nxt],nxt);
        y.first++;
        if(x.first ==y.first)ans = {x.first,(x.second+y.second)%mod};
        else ans = min(x,y);
    }   
    else{
        ans = solve(idx+1,last);
    }
    return x= ans;
    
}

signed main(){__
    int T = 1;
    cin>>T;
    while(T--){
        string s,t;
        cin>>s;
        cin>>t;
        n = s.size();
        m = t.size();
        for(int i = 0;i<n;i++)Match[i] = false;
        Index = match(s,t);
        if(Index.size()==0){
            cout<<"0 1"<<endl;
            continue;
        }
        Index.push_back(n);
        M = Index.size();
        memset(dp,-1,sizeof(dp));
        auto ans = solve(0,0);
        cout<<ans.first<<" "<<ans.second<<endl;
        
    }
    return 0;
}