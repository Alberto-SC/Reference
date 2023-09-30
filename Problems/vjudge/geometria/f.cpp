#include <bits/stdc++.h>
using namespace std;
int movesx[] = {0,0,-1,1};
int movesy[] = {1,-1,0,0};
const int inf = INT_MAX;
int main(){
    int n,x,y,a,b;
    cin>>n>>x>>y;
    vector<int> count(4,0);
    vector<pair<int,int>> dist(4);
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        for(int j =0 ;j<4;j++){
            dist[j] = {inf,j};
            int nx,ny;
            nx = x+movesx[j];
            ny = y+movesy[j];
            if(nx<0|| ny<0)continue;
            dist[j].first = abs(nx-a)+abs(ny-b);
        }
        sort(dist.begin(),dist.end());
        int j = 1;
        count[dist[0].second]++;
        while(j<4&&dist[j].first== dist[0].first){count[dist[j].second]++;j++;}

    }
    int mx = 0;
    int index = 0;
    for(int i = 0;i<4;i++){
        if(count[i]>mx){
            mx = count[i];
            index = i;
        }
    }
    cout<<mx<<endl;
    cout<<x+movesx[index]<<" "<<y+movesy[index]<<endl;
    return 0;
}