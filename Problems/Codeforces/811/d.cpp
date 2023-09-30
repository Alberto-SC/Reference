#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int T= 1,n;
    cin>>T;
    while(T--){
        string t;
        cin>>t;
        cin>>n;
        int N = t.size();
        vector<string> S(n);
        for(auto &c:S)cin>>c;
        vector<int> mx(N);
        vector<int> segment(N,-1);
        vector<pair<int,int>> res(N);
        for(int i=0;i<n;i++){
            int L = S[i].size();
            for(int k = 0;k<=N-L;k++){
                bool flag = true; 
                for(int l = 0;l<L;l++){
                    if(t[k+l]!=S[i][l])
                        flag = false;
                }
                if(flag){
                    for(int l = 0;l<L;l++){
                        if((k+L)> segment[k+l]){
                            segment[k+l] = max(segment[k+l],(k+L));
                            res[k+l] = {i,k};
                        }
                    }
                }
            }
        }
        int idx = 0;
        bool flag = true;
        int ans = 0;
        vector<pair<int,int>> ANS;
        while(1){
            if(segment[idx]==-1){
                flag = false;
                break;
            }
            ANS.push_back(res[idx]);
            idx = segment[idx];
            ans++;
            if(idx == N)break;
        }
        if(flag){
            cout<<ans<<endl;
            for(auto c:ANS)cout<<c.first+1<<" "<<c.second+1<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}  
