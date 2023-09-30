#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t,x,y;
    cin>>t;
    int cont = 1;
    while(t--){
        cin>>n>>m;
        set<int> st[n+1];
        bool flag = true;
        for(int i = 0;i<m;i++){
            cin>>x>>y;
            if(st[x].find(y)!= st[x].end())flag = false;
            st[x].insert(y);
        }
        if(flag)cout<<"Scenario #"<<cont<<": possible"<<endl;
        else cout<<"Scenario #"<<cont<<": impossible"<<endl;
        cont++;
    }
    return 0;
}