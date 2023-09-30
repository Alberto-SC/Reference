#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair<int, int> pi;
#define x first
#define y second
signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> A(k);
        vector<int> T(k);
        for(auto &c:A)cin>>c;
        for(auto &c:T)cin>>c;
        priority_queue<pi,vector<pi>, greater<pi>> C;
        for(int i = 0;i<k;i++){
            C.push({T[i],A[i]-1});
        }
        vector<int> ans(n,-1);
        while(!C.empty()){
            pi c = C.top();
            C.pop();
            if(ans[c.y]==-1|| ans[c.y]> c.x)
                ans[c.y]= c.x;
            if(c.y-1>=0 && (ans[c.y-1]> c.x+1|| ans[c.y-1]==-1)){
                C.push({c.x+1,c.y-1});
                ans[c.y-1] = c.x+1;
            }
            if(c.y+1<n && (ans[c.y+1]> c.x+1 || ans[c.y+1]==-1)){
                ans[c.y+1] = c.x+1;
                C.push({c.x+1,c.y+1});
            }
        } 
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
