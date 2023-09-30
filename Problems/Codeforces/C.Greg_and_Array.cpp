#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
const int MAXN = 100007;
typedef long long int lli;
vector<lli> stM(4*MAXN);
vector<lli> stA(4*MAXN);
vector<lli> lazy(4*MAXN,0);
vector<lli> lazy2(4*MAXN,0);
void propagate_sum(int v ,int SL, int SR){
    if(lazy[v] == 0)return ;
    stM[v] =stM[v]+ lazy[v];
    if(SL!=SR){
        lazy[v*2] = lazy[v*2]+lazy[v];
        lazy[v*2+1] =lazy[v*2+1]+lazy[v];
    }
    lazy[v] = 0;
}
                                                                      
void Update_sum(int v, int SL, int SR, int L, int R, lli mult){ 
    propagate_sum(v,SL,SR);
    if(SL>SR || SR<L || R<SL)return;
    if(L<=SL && SR<=R){
        lazy[v] =(lazy[v]+mult);
        propagate_sum(v,SL,SR);
        return;
    }
    int SM = (SL+SR)/2;
    Update_sum(v*2,SL,SM,L,R,mult);
    Update_sum(v*2+1,SM+1,SR,L,R,mult);
    stM[v] = (stM[v*2]+stM[v*2+1]);
}
lli query_sum(int v,int SL,int SR,int L,int R){
    propagate_sum(v,SL,SR);
    if(SL>SR || SR<L || R<SL)return 0;
    if(L<=SL && SR<=R)return stM[v];
    int SM = (SL+SR)/2;
    lli p1 = query_sum(v*2,SL,SM,L,R);
    lli p2 = query_sum(v*2+1,SM+1,SR,L,R);
    return (p1+p2);
}


void propagate_sum2(int v,int SL, int SR){
    if(lazy2[v]==0)return ;
    stA[v] = (stA[v]+lazy2[v]);
    if(SL !=SR){
        lazy2[v*2] = lazy2[v*2]+lazy2[v];
        lazy2[v*2+1] = lazy2[v*2+1]+lazy2[v];
    }
    lazy2[v] = 0;
}    
void Update_sum2(int v, int SL, int SR, int L, int R, lli val){ 
    propagate_sum2(v,SL,SR);
    if(SL>SR || SR<L || R<SL)return;
    if(L<=SL && SR<=R){
        lazy2[v] =(lazy2[v]+val);
        propagate_sum2(v,SL,SR);
        return;
    }
    int SM = (SL+SR)/2;
    Update_sum2(v*2,SL,SM,L,R,val);
    Update_sum2(v*2+1,SM+1,SR,L,R,val);
    stA[v] = (stA[v*2]+stA[v*2+1]);
}

lli query_sum2(int v,int SL,int SR,int L,int R){
    propagate_sum2(v,SL,SR);
    if(SL>SR || SR<L || R<SL)return 0;
    if(L<=SL && SR<=R)return stA[v];
    int SM = (SL+SR)/2;
    lli p1 = query_sum2(v*2,SL,SM,L,R);
    lli p2 = query_sum2(v*2+1,SM+1,SR,L,R);
    return (p1+p2);
}
int main(){
    lli n,m,k,a,b,d;
    cin>>n>>m>>k;
    vector<lli> array(n);
    vector<pair<pair<int,int>,int>> queries(m);
    for(auto &c:array)cin>>c;
    for(int i = 0;i<m;i++)Update_sum(1,0,m-1,i,i,0);
    for(int i = 0;i<n;i++)Update_sum2(1,0,n-1,i,i,array[i]);
    for(int i = 0;i<m;i++){
        cin>>a>>b>>d;
        queries[i] = {{a,b},d};
    }
    for(int i = 0;i<k;i++){
        cin>>a>>b;
        a--;
        b--;
        Update_sum(1,0,m-1,a,b,1);
    }
    // for(int i = 0;i<n;i++)cout<<query_sum(1,0,m-1,i,i)<<" ";
    // cout<<endl;
    for(int i = 0;i<m;i++){
        Update_sum2(1,0,n-1,queries[i].x.x-1,queries[i].x.y-1,queries[i].y*query_sum(1,0,m-1,i,i));
    }
    for(int i = 0;i<n;i++)
        cout<<query_sum2(1,0,n-1,i,i)<<" ";
    return 0;
}
// 3 3 3
// 1 2 3
// 1 2 1
// 1 3 2
// 2 3 4
// 1 2
// 1 3
// 2 3