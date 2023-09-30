#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<int> pos[maxn];

int n,m,k,c;
int find(int u){
    if(pos[u].size()== 0)return 0;
    int last  = 0,ans = 1,ac = 0,gap;
    for(int i = 1;i<pos[u].size();i++){
        gap = (pos[u][i]-pos[u][i-1])-1;
        ac += gap;
        while(ac>k){
            last++;
            ac-= (pos[u][last]-pos[u][last-1])-1;
        }
        ans = max(ans,(i-last)+1);
    }
    return ans;
}

int main(){
    cin>>n>>m>>k;
    for(int i = 0;i<n;i++){
        cin>>c;
        pos[c].push_back(i);
    }
    int ans = 0;
    for(int i = 1;i<=m;i++)
        ans = max(ans,find(i));
    cout<<ans<<endl;
    return 0;
}