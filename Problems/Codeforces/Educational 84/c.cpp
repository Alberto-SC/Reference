#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,m,k,x,y;
    cin>>n>>m>>k;
    pair<int,int> mx = {-1,-1};
    for(int i = 0;i<k;i++){
        cin>>x>>y;
    }
    cout<<m-1+n-1 + (n*m-1)<<endl;
    for(int i = 0;i<k;i++)
        cin>>x>>y;
    for(int i = 0;i<m-1;i++)
        cout<<"L";
    for(int i = 0;i<n-1;i++)
        cout<<"U";

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m-1;j++){
            if(i&1)cout<<"L";
            else cout<<"R";
        }
        if(i <n-1)
        cout<<"D";
    }
    cout<<endl;
}

