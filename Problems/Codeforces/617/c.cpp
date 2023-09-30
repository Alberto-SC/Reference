#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        int x = 0,y = 0,xans,yans;
        map<pair<int,int>,int> path;
        path[{0,0}]=0;
        int mn = 1000007,ansl=0,ansr=0;
        for(int i = 0;i<n;i++){
            if(s[i]=='L')x--;
            if(s[i]=='R')x++;
            if(s[i]=='U')y++;
            if(s[i]=='D')y--;
            if(path.find({x,y})!=path.end())
                if(i-path[{x,y}]<mn)mn = i-path[{x,y}],ansl=path[{x,y}]+1,ansr=i+1;
            path[{x,y}]=i+1;
        }
        // for(auto c: path)cout<<c.first.first<<" "<<c.first.second<<" "<<c.second<<endl;
        // cout<<path.size()<<endl;
        if(ansl!= 0 && ansr!=0)cout<<ansl<<" "<<ansr<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}