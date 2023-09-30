#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

struct TwoSat {
	int N;
	vector<vector<int>> gr;
	vector<int> values; // 0 = false, 1 = true
	TwoSat(int n = 0) : N(n), gr(2*n) {}
	void addCondition(int u, int v,int Nu,int Nv) {
        (u*=2)^=Nu;
        (v*=2)^=Nv;
		gr[u^1].push_back(v);
		gr[v^1].push_back(u);
	}

	vector<int> val, comp, z; 
    int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(auto e: gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		++time;
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = time;
			if (values[x>>1] == -1)
				values[x>>1] = !(x&1);
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		for(int i = 0;i<2*N;i++) 
            if(!comp[i]) 
                dfs(i);
		for(int i = 0;i<N;i++) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

signed main(){__
    int t,n,k;
    cin>>n>>k;
    vector<string> V(n);
    for(auto &c:V)cin>>c;
    string ans = string(k,'F');
    for(int pos = 0;pos<k;pos++){
        TwoSat ts(k);
        for(int i = 0;i<n;i++){
            for(int a = 0;a<k;a++){
                if(V[i][a]== 'X')continue;
                for(int b = a+1;b<k;b++){
                    if(V[i][b]== 'X')continue;
                    ts.addCondition(a,b,V[i][a]== 'T',V[i][b]== 'T');
                }
            }
        }
        for(int i = 0;i<pos;i++){
            if(ans[i]=='T')ts.addCondition(i,i,0,0);
            else ts.addCondition(i,i,1,1);
        }

        ts.addCondition(pos,pos,1,1);
        if(ts.solve())ans[pos] = 'F';
        else ans[pos] = 'T';
        for(int i = 0;i<k;i++){
            cout<<ts.values[i]<<" ";
        }
        cout<<endl;
    }
    for(int i = 0;i<n;i++){
        int cont = 0;
        for(int j = 0;j<k;j++)
            cont+= ans[j]== V[i][j];
        if(cont>1)return cout<<-1<<endl,0;
    }
    cout<<ans<<endl;
}   