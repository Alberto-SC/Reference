#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    vector<vector<int>> grid(n,vector<int> (n,0)) 
    for(int i = 0;i<n;i++){
        cin>>s;
        for(int j = 0;j<n;j++)if(s[j] == 'B')grid[i][j]= 1;
    }
    vecor<pair<int,int>> posr(n);
    vecor<pair<int,int>> posc(n);
    for(int i = 0;i<n;i++){
        int j = 0;
        while(j<n && grid[i][j]==0)j++;
        if(j == n){posr[i] = {0,n-1};continue;}
        int k = n-1;
        while(j>=0 && grid[i][k] == 0)j--;
        posr[i] = {j,k};
    }
    for(int i = 0;i<n;i++){
        int j = 0;
        while(j<n && grid[j][i]==0)j++;
        if(j == n){posc[i] = {0,n-1};continue;}
        int k = n-1;
        while(j>=0 && grid[k][i] == 0)j--;
        posc[i] = {j,k};
    }
    for(int i = 0;i<n;i++){
        for(int j = k;j<n-k;j++){

        }
    }

    return 0;
}