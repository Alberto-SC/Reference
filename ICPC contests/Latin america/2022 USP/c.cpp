#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


const int N = 500007;
int t[N];
int nxt[N][26];

int szt = 1; 
int new_vertex(){  
	t[szt] = 0;
	return szt++;
}
 
int go(int x, int y){
	if (nxt[x][y] == -1)
		nxt[x][y] = new_vertex();
	return nxt[x][y];
}
 
void add(string s,int pw){
	int cur = 0;
	for(int i = 0;i<s.size();i++){
		cur = go(cur, s[i]-'a');
	}
  t[cur] = pw;
}

long long ans =0;
void dfs(int curr,long long sum = 0){
  sum+=t[curr];
  ans = max(ans,sum);
  for(int i = 0;i<26;i++){
    if(nxt[curr][i]==-1)continue;
    dfs(nxt[curr][i],sum);
  }
}

signed main(){
    int t;
    string s;
    cin >> t;
    memset(nxt,-1,sizeof(nxt));
    while(t--){
        cin >> s;
        int pi;
        cin>>pi;
        add(s, pi);
    }
    dfs(0);
    cout<<ans<<endl;

    return 0;
}
