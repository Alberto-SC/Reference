#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    while(true){
        vector<int> C(n+m+1,0);
        int mx = -10000;
        for(int i = 2;i<=n+1;i++){
            C[i] = min(i-1,m);
            mx = max(C[i],mx);
        }
        for(int i = n+2;i<=n+m;i++){
            C[i] = min(n,m-((i-1)-n));
            mx = max(C[i],mx);
        }
        for(int i = 2;i<n+m;i++){
            if(C[i] == mx)cout<<i<<"\n";
        }
        if(cin>>n>>m)cout<<"\n";
        else break;
    }
    return 0;
}