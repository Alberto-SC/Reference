#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 1007;
vector<int> nums(maxn);
int main(){
    int n,u,v;
    cin>>n;
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    cin>>q;
    for(int i = 0;i<n;i++){
        cin>>type;
        if(type == 1){
            cin>>u>>v;
            u--,v--;
            int x = dfs(u,);

        }
        else {
            cin>>u>>k;
            u--;
            nums[u] = k;
        }
    }
    cout<<endl;
    return 0;
}