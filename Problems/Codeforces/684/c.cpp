#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
struct ans{
    int x1,y1,x2,y2,x3,y3;
    ans operator+(const ans B){
        return (ans){x1+B.x1,y1+B.y2,x2+B.x2,y2+B.y2,x3+B.x3,y3+B.y3};
    }
};

map<vector<int>,ans> mp;

int main(){
    mp[{1,0,0,0}] = {1,1,2,1,2,2};
    mp[{0,1,0,0}] = {1,1,1,2,2,1};
    mp[{0,0,1,0}] = {2,1,1,1,1,2};
    mp[{0,0,0,1}] = {2,2,2,1,1,2};
    mp[{1,1,0,0}] = {2,1,2,2,1,1};
    mp[{1,0,1,0}] = {1,2,2,2,1,1};
    mp[{1,0,0,1}] = {1,2,2,1,2,2};
    mp[{0,1,1,0}] = {1,2,1,1,2,2};
    mp[{0,1,0,1}] = {1,1,1,2,2,1};
    mp[{0,0,1,1}] = {1,1,1,2,2,1};
    mp[{0,1,1,1}] = {1,2,2,1,2,2};
    mp[{1,0,1,1}] = {1,1,2,1,2,2};
    mp[{1,1,0,1}] = {1,1,1,2,2,2};
    mp[{1,1,1,0}] = {1,1,1,2,2,1};
    mp[{1,1,1,1}] = {1,1,1,2,2,1};
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        char c;
        vector<vector<int>> grid(n,vector<int>(m));
        int zero = 0;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin>>c,grid[i][j] = (int)(c-'0'),zero+=!grid[i][j];
        vector<ans>res;
        if(n&1){
            for(int i = 0;i<m-1;i++){
                if(grid[n-1][i]){
                    grid[n-1][i] = !grid[n-1][i];
                    grid[n-2][i] = !grid[n-2][i];
                    grid[n-2][i+1] = !grid[n-2][i+1];
                    res.push_back({n-1,i,n-2,i,n-2,i+1});
                }
            }
            if(grid[n-1][m-1]){
                grid[n-1][m-1] = !grid[n-1][m-1];
                grid[n-2][m-1] = !grid[n-2][m-1];
                grid[n-2][m-2] = !grid[n-2][m-2];
                res.push_back({n-1,m-1,n-2,m-1,n-2,m-2});
            }
        }
        if(m&1){  
            if(n&1){
                for(int i = 0;i<n-2;i++){
                    if(grid[i][m-1]){
                        grid[i][m-1] = !grid[i][m-1];
                        grid[i][m-2] = !grid[i][m-2];
                        grid[i+1][m-2] = !grid[i+1][m-2];
                        res.push_back({i,m-1,i,m-2,i+1,m-2});
                    }   
                }
                if(grid[n-2][m-1]){
                    grid[n-2][m-1] = !grid[n-2][m-1];
                    grid[n-2][m-2] = !grid[n-2][m-2];
                    grid[n-3][m-2] = !grid[n-3][m-2];
                    res.push_back({n-2,m-1,n-2,m-2,n-3,m-2});
                }

            }
            else{
                for(int i = 0;i<n-1;i++){
                    if(grid[i][m-1]){
                        grid[i][m-1] = !grid[i][m-1];
                        grid[i][m-2] = !grid[i][m-2];
                        grid[i+1][m-2] = !grid[i+1][m-2];
                        res.push_back({i,m-1,i,m-2,i+1,m-2});
                    }   
                }
                if(grid[n-1][m-1]){
                    grid[n-1][m-1] = !grid[n-1][m-1];
                    grid[n-1][m-2] = !grid[n-1][m-2];
                    grid[n-2][m-2] = !grid[n-2][m-2];
                    res.push_back({n-1,m-1,n-1,m-2,n-2,m-2});
                }
            }
            
        }
        // for(int i = 0;i<n;i++)
            // for(int j = 0;j<m;j++)
                // cout<<grid[i][j]<<" \n"[j==m-1];
        for(int i = 0;i<n;i+=2){
            for(int j = 0;j<m;j+=2){
                vector<int> x;
                if(j+1>=m || i+1>=n)continue;
                x.push_back(grid[i][j]);
                x.push_back(grid[i][j+1]);
                x.push_back(grid[i+1][j]);
                x.push_back(grid[i+1][j+1]);
                while(grid[i][j]||grid[i][j+1]|| grid[i+1][j] ||grid[i+1][j+1]){
                    ans z = mp[x];
                    grid[i+z.x1-1][j+z.y1-1] = !grid[i+z.x1-1][j+z.y1-1];
                    grid[i+z.x2-1][j+z.y2-1] = !grid[i+z.x2-1][j+z.y2-1];
                    grid[i+z.x3-1][j+z.y3-1] = !grid[i+z.x3-1][j+z.y3-1];
                    x.clear();
                    x.push_back(grid[i][j]);
                    x.push_back(grid[i][j+1]);
                    x.push_back(grid[i+1][j]);
                    x.push_back(grid[i+1][j+1]);
                    res.push_back({i+z.x1-1,j+z.y1-1,i+z.x2-1,j+z.y2-1,i+z.x3-1,j+z.y3-1});
                }
                
            }
        }
        // for(int i = 0;i<n;i++)
        //     for(int j = 0;j<m;j++)
        //         cout<<grid[i][j]<<" \n"[j==m-1];
        if(res.size()>n*m)return cout<<"NEL"<<endl,0;
        cout<<res.size()<<endl;
        for(auto c:res)
            cout<<c.x1+1<<" "<<c.y1+1<<" "<<c.x2+1<<" "<<c.y2+1<<" "<<c.x3+1<<" "<<c.y3+1<<endl;
    }
    return 0;
}  
