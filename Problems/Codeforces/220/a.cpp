#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int t= 1,n,m,x,y,a,b;

int check(int x1,int y1){
    if(abs(x1-x)%a)return -1;
    if(abs(y1-y)%b)return -1;
    if((abs(x1-x)/a)>(abs(y1-y)/b)){
        int moves = abs(x1-x)/a;
        int minmoves = abs(y1-y)/b;
        if((moves-minmoves)% 2==0){
            if((moves-minmoves)>0 && y+b>m && y-b<=0)
                return -1;
            return moves;
        }
    }
    else{
        int moves = abs(y1-y)/b;
        int minmoves = abs(x1-x)/a;
        if((moves-minmoves)%2 == 0){
            if(moves-minmoves>0 && x1+a>n && x1-a<=0)
                return -1;
            return moves;
        }
    }
    return -1;

}
int main(){__
    cin>>n>>m;
    cin>>x>>y;
    cin>>a>>b;
    int ans = (n+m)+700;
    int cont = 0;
    int x1= 1,y1 = 1;
    if(check(x1,y1)!=-1)
        ans = min(ans,cont+check(x1,y1));

    x1 = 1,y1 = m,cont = 0;
    if(check(x1,y1)!=-1)
        ans = min(ans,cont+check(x1,y1));
    
    x1 = n,y1 = 1,cont = 0;
    if(check(x1,y1)!=-1)
        ans = min(ans,cont+check(x1,y1));
    
    x1 = n,y1 = m,cont = 0;
    if(check(x1,y1)!=-1)
        ans = min(ans,cont+check(x1,y1));
    
    if(ans == m+n+700)cout<<"Poor Inna and pony!"<<endl;
    else 
        cout<<ans<<endl;
    return 0;
}  

