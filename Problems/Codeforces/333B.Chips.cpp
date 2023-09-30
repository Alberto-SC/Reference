#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y,m;
    cin>>n>>m;
    vector<bool> cols(n,true);
    vector<bool> rows(n,true);
    for(int i = 0;i<m;i++){
        cin>>x>>y;
        x--,y--;
        cols[y] = false;
        rows[x] = false;
    }
    int ans = 0;
    for(int i = 1;i<n-1;i++){
        if(n&1 && i == n/2)continue;
        int r = rows[i]+rows[(n-1)-i];
        int c = cols[i]+cols[(n-1)-i];
        if(r>c){
            ans+=r;
            rows[i] = false;
            rows[(n-1)-i] = false;
        }
        else{
            ans+=c;
            cols[i] = false;
            cols[(n-1)-i] = false;
        }
    }
    
    if(n&1 && (rows[n/2] || cols[n/2]))ans++;
    cout<<ans<<endl;
    return 0;
}