#include<bits/stdc++.h>

using namespace std;

int movsX[] = {-2,-1,+1,+2,+2,+1,-1,-2};
int movsY[] = {+1,+2,+2,+1,-1,-2,-2,-1};

#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    int H,W,N,x,y,D;
    cin>>H>>W>>N;
    int mg[H][W];
    int dis[H][W];
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            mg[i][j]=0;

    bool allEqual = true;
    bool first = true;
    int tx, ty;
    int inf = 1e6;
    while(N--){
        bool mt[H][W]={false};
        for(int i=0; i<H; i++)
            for(int j=0; j<W; j++)
                dis[i][j] = inf;

        cin>>x>>y>>D;
        x--,y--;
        queue<pair<int,int>> q;
        q.push({x,y});
        dis[x][y] = 0;
        while(!q.empty()){ 
            auto actual=q.front();
            q.pop();
            for(int i=0; i < 8; i++){ // movimientos caballo
                int nX = actual.first+movsX[i];
                int nY = actual.second+movsY[i];
                if(nX>=0 and nX<H and nY>=0 and nY<W and (dis[actual.first][actual.second]+1)<dis[nX][nY]){
                    dis[nX][nY]=dis[actual.first][actual.second]+1;
                    q.push({nX,nY});
                }
            }
        }
        for(int i = 0;i<H;i++)
            for(int j = 0;j<W;j++)
                mg[i][j]+=ceil(dis[i][j]/(D*1.0));
    }
    int mini = INT_MAX;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            mini = min(mini, mg[i][j]);
        }
    }
    if(mini>=inf) cout<<"-1\n";
    else cout<<mini<<"\n";

    return 0;
}
