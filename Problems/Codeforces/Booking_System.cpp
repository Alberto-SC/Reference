#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second

int main(){
    int n,m;
    cin>>n;
    vector<pair<pair<int,int>,int>> req(n);
    for(int i = 0;i<n;i++){
        cin>>req[i].x.y>>req[i].x.x;
        req[i].y = i;
    }
    cin>>m;
    vector<pair<int,int>> tables(m);
    for(int i = 0;i<m;i++){
        cin>>tables[i].x;
        tables[i].y = i;
    }
    sort(tables.begin(),tables.end());
    sort(req.rbegin(),req.rend());
    vector<int> ans(n,-1);
    vector<bool> used(m,false);
    int cont = 0,res = 0;
    for(int i = 0;i<n;i++){
        int index = lower_bound(tables.begin(),tables.end(),make_pair(req[i].x.y,-1))-tables.begin();
        while(index<m &&used[index])index++; 
        if(index== m)continue;
        used[index]= true;
        cont++;
        res+=req[i].x.x;

        ans[req[i].y] = tables[index].y+1;
    }
    cout<<cont<<" "<<res<<endl;
    for(int i = 0;i<n;i++){
        if(ans[i]!= -1)cout<<i+1<<" "<<ans[i]<<endl;
    }
    return 0;
}