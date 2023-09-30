#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid(1000,vector<int>(0,1000));
vector<vector<bool>> grid(1000,vector<int>(false,1000));
int n,m;
searchStar(int i,int j){
    int cont = 0,k = i,l = j;
    while(grid[k][l]== 1){
        l++;
        if(k-cont<0)continue;
        bool flag = true;
        for(int i = k;i>=k-cont;i--)
            if(grid[i][l])!=1)flag = false;
        if(k+cont>=n)continue;
        for(int i = k;i<=k+cont;i++)
            if(grid[i][l])!=1)flag = false;
        if(flag){
            for(int i = k;i>=k-cont;i--)
                used[i][l] = true;
            for(int i = k;i<n;i++)
                if(grid[i][l])!=1)flag = false;
        }
        cont++;
};

int main(){
    cin>>n>>m;
    char c;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>c;
            if(c=='*')grid[i][j] = 1;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(grid[i][j] =='*' && used[i][j]==false)
        }
    }
    return 0;
}