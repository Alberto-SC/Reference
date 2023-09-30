#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m;
    cin>>n>>m;
    if(n== 1 && m == 1)return cout<<0<<endl,0;
    if(m == 1){
        for(int i = 0;i<n;i++)
            cout<<i+2<<endl;
        return 0;
    }
    int matrix[n][m];
    for(int i = 0;i<m;i++)
        cout<<i+2<<" ";
    cout<<endl;
    int init = m+2;
    for(int i = 1;i<n;i++){
        for(int j = 2;j<m+2;j++)
            cout<<j*init<<" ";
        cout<<endl;
        init++;
    } 
    return 0; 
}  

