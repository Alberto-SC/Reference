#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int inf = 1LL << 62;
vector<vector<int>> floydWarshall(vector<vector<int>>& m,vector<int> &val) {
	int n = m.size();
    vector<vector<int>>ans(n,vector<int> (n));

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(m[i][j]!=inf){
                ans[i][j] = val[i]+val[j];
            }
        }
    }


	for(int k = 0;k<n;k++)
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
				if (m[i][k] != inf && m[k][j] != inf) {
					auto newDist = m[i][k] + m[k][j];

                    if (newDist <m[i][j]){
                        m[i][j] = newDist;
                        ans[i][j] = ans[i][k]+ans[k][j] -val[k];
                    }
                    else if(newDist == m[i][j]){
                        ans[i][j] = max(ans[i][j], ans[i][k]+ans[k][j] -val[k]);
                    }
				}

    return ans;
}


signed main(){__
    int T = 1,n,u,v;
    cin>>n;
    vector<vector<int>> m(n,vector<int> (n));

    vector<int> nums(n);
    for(auto &c:nums)cin>>c;

    for(int i= 0;i<n;i++){
        string s;
        cin>>s;
        for(int j = 0;j<n;j++){
            if(s[j]== 'Y')
                m[i][j] = 1;
            else m[i][j] = inf;
        }
    }

    vector<vector<int>> ans = floydWarshall(m,nums);
    cin>>T;
    while(T--){
        cin>>u>>v;
        u--,v--;
        if(m[u][v]== inf)cout<<"Impossible"<<endl;
        else 
            cout<<m[u][v]<<" "<<ans[u][v]<<endl;
    }
    return 0;
}