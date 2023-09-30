#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first 
#define y second

int n,m;
bool valid(int a,int b){
    if(a>=n || b>=m)return false;
    if(a<0 || b< 0)return false;
    return true;
}
int main(){__
	int t= 1;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<string> grid(n);
        for(auto &c:grid)cin>>c;
        int cont = 0;
        vector<int> l[n];
        vector<int> r[n];
        int ans = 0;
        for(int i = 0;i<n;i++){
            l[i].resize(m);
            for(int j = 0;j<m;j++){
                if(grid[i][j]== '.')l[i][j] = 0;
                else if(grid[i][j] == '*' && j)l[i][j] = 1+l[i][j-1];
                else if(grid[i][j] == '*' && !j)l[i][j] = 1;
            }
        }
        for(int i = 0;i<n;i++){
            r[i].resize(m);
            for(int j = m-1;j>=0;j--){
                if(grid[i][j]== '.')l[i][j] = 0;
                else if(grid[i][j] == '*' && j<m-1)r[i][j] = 1+r[i][j+1];
                else if(grid[i][j] == '*' && j ==m-1)r[i][j] = 1;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int k = i;k<n;k++){
                    if(l[k][j]< (k-i)+1)break;
                    if(r[k][j]< (k-i)+1)break;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  

