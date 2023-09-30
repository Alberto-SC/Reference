#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int f[8][8][2];
map<int,int> dp;
char M[8][8];
int n,m,t;
const int inf = 1e15;
pair<int,int> nextE(int x,int y){
    if(y+2>=m){
        x++;
        y=0;
        if(x>= n)return {-1,-1};
        return {x,y};
    }
    else {
        return {x,y+2};
    }
}
pair<int,int> nextN(int x,int y){
    if(y+1>=m){
        x++;
        y=0;
        if(x>= n)return {-1,-1};
        return {x,y}; 
    }
    else {
        return {x,y+1};
    }
}

bool isNeed(int x,int y){
    if(f[M[x][y]][x][0])return true;
    if(f[M[x][y]][y][1])return true;
    return false;
}

bool isPoss(int mask,int x,int y){
    int up = ((x-1)*m)+y;
    int left = (x*m)+(y-1);
    if(mask>>up)return false;
    if(mask>>left)return false;
    return true; 
}

int solve(int mask,int x,int y){
    if(dp.count(mask)) return dp[mask];
    int ans = 1e15;
    if(isNeed(x,y)){
        if(isPoss(mask,x,y)){
            pair<int,int> nx = nextE(x,y);
            if(nx.first!=-1){
                f[M[x][y]][x][0]--;
                f[M[x][y]][y][1]--;
                ans  = min(ans,solve(mask|((x*m)+y),nx.first,nx.second));
                f[M[x][y]][x][0]++;
                f[M[x][y]][y][1]++;
            }
            else{
                nx = nextN(x,y);
                if(nx.first!=-1){
                    ans  = min(ans,solve(mask,nx.first,nx.second));
                }
                else{
                    bool flag = true;
                    for(int i = 0;i<t;i++)
                        for(int j = 0;j<n;j++)
                                if(f[i][j][0]>1)flag = false;
                    for(int i = 0;i<t;i++)
                        for(int j = 0;j<m;j++)
                                if(f[i][j][0]>1)flag = false;
                    if(flag)
                        return __builtin_popcount(mask);
                    return inf;
                }
            }
        }
        else{
            pair<int,int> nx = nextN(x,y);
            if(nx.first!= -1){
                ans = solve(mask,nx.first,nx.second);
            }
            else{
                bool flag = true;
                for(int i = 0;i<t;i++)
                    for(int j = 0;j<n;j++)
                            if(f[i][j][0]>1)flag = false;
                for(int i = 0;i<t;i++)
                    for(int j = 0;j<m;j++)
                            if(f[i][j][0]>1)flag = false;
                if(flag)
                    return __builtin_popcount(mask);
                return inf;
            }
        }
    }
    else{
        pair<int,int> nx = nextN(x,y);
        if(nx.first!= -1){
            dp[mask]=solve(mask,nx.first,nx.second);
        }
        else{
            bool flag = true;
            for(int i = 0;i<t;i++)
                for(int j = 0;j<n;j++)
                        if(f[i][j][0]>1)flag = false;
            for(int i = 0;i<t;i++)
                for(int j = 0;j<m;j++)
                        if(f[i][j][0]>1)flag = false;
            if(flag)
                return __builtin_popcount(mask);
            return inf;
        }
    }
    return dp[mask];
}  

signed main(){__
    cin>>n>>m>>t;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>M[i][j];
            f[M[i][j]-'A'][i][0]++;
            f[M[i][j]-'A'][j][1]++;
        }
    }
    cout<<solve(0,0,0)<<endl;
    return 0;
}  
