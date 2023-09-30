#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dist[100][10][10];
const lli inf = 100000;
lli get(lli a,lli b){
    return (a*10)+b;
}
lli x,y;
void make_graph(lli n ,lli a,lli sum){
    if(dist[n][sum%10][(sum+a)%10]== 1)return;
    dist[n][sum%10][(sum+a)%10] = 1;
    make_graph(n,x,sum+a);
    make_graph(n,y,sum+a);
}

void all_dist(lli n){
    for (lli k = 0; k < 10; ++k) {
        for (lli i = 0; i < 10; ++i) {
            for (lli j = 0; j < 10; ++j) {
                dist[n][i][j] = min(dist[n][i][j], dist[n][i][k] + dist[n][k][j]); 
            }
        }
    }
}

void precalc(){
    for(int i = 0;i<100;i++)
        for(int j = 0;j<10;j++)
            for(int k = 0;k<10;k++)dist[i][j][k] = inf;
    
    for(lli i = 0;i<10;i++){
        for(lli j = i;j<10;j++){
            x = i,y = j;
            make_graph(get(i,j),i,0);
            make_graph(get(i,j),j,0);
        }
    }
    for(lli i = 0;i<10;i++){
        for(lli j = i;j<10;j++){
            all_dist(get(i,j));
        }
    }

}

lli ans[10][10];
int main(){
    string s;
    cin>>s;
    precalc();    
    for(lli i = 0;i<10;i++){
        for(lli j = i;j<10;j++){
            lli n = get(i,j);
            for(lli k = 1;k<s.size();k++){
                if(dist[n][s[k]-'0'][s[k-1]-'0']>= inf){ans[i][j] = -1;break;}
                ans[i][j] += dist[n][s[k-1]-'0'][s[k]-'0']-1;
            
            }
            ans[j][i]= ans[i][j];
        }
    }
    for(lli i = 0;i<10;i++)
        for(lli j = 0;j<10;j++)
            cout<<ans[i][j]<<" \n"[j == 9];

    return 0;
}