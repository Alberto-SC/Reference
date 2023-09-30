#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>n;
    int grid[n][n];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin>>grid[i][j];
    vector<int> rows(n);
    vector<int> cols(n);
    for(int i = 0;i<n;i++){
        int sum = 0,sum2 = 0;
        for(int j = 0;j<n;j++){
            sum+=grid[i][j];
            sum2+= grid[j][i];
        }
        cols[i] = sum2;vv
        rows[i] = sum;
    }
    int cont = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(cols[j]>rows[i])cont++;
        }   
    }
    cout<<cont<<endl;
    return 0;
}  

