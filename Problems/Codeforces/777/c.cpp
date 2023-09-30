#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

struct ANS{
    int x1,y1,x2,y2;
};

signed main(){__
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        char M[n][m];
        for(int i = 0;i<n;i++)
            for(int j= 0;j<m;j++)
                cin>>M[i][j];
        bool flag = true;
        vector<ANS>ans;
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(M[i][j] == '0')continue;
                if(j){
                    ans.push_back({i,j-1,i,j});
                }
                else if(i){
                    ans.push_back({i-1,j,i,j});
                }
                else{
                    flag = false;
                }
            }
        }
        if(!flag)cout<<-1<<endl;
        else{
            cout<<ans.size()<<endl;
            for(auto c:ans)cout<<c.x1+1<<" "<<c.y1+1<<" "<<c.x2+1<<" "<<c.y2+1<<endl;
        }
    }
}   