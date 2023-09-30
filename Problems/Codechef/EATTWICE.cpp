#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m,d,v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> t(m+1,0);
        for(int i = 0;i<n;i++){
            cin>>d>>v;
            if(v>t[d])t[d] =v;
        }
        sort(t.begin(),t.end());
        cout<<t[m]+t[m-1]<<"\n";
    }
    return 0;
}