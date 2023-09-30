#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    lli t,n,x,y;
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        int diff = y-x;
        int ans = 10000,div,cont;
        for(int i = 1;i<=50;i++){
            cont = 0;
            bool flag = false;
            int j;
            int mx = -1;
            for(j = x;j<=y && cont<n;j+=i){
                if(j == y)flag = true;
                cont++;
                mx = max(mx,j);
            }
            if(!flag)continue;
            for(j = x-i;j>0;j-=i){
                mx = max(j,mx);
                cont++;
            }
            if(cont<n){
                for(j = y+i;cont<n;j+=i){
                    cont++;
                    mx = max(mx,j);
                }
            }
            // cout<<mx<<" "<<i<<endl;
            if(mx<ans){
                ans = mx;
                div = i;
            }
        }
        cont = 0;
        for(int i = x;i<=y;i+=div){
            cout<<i<<" ";
            cont++;
        }
        for(int i = x-div;cont<n && i>0;i-=div){
            cont++;
            cout<<i<<" ";
        }
        if(cont<n){
            for(int i = y+div;cont<n;i+=div){
                cont++;
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

