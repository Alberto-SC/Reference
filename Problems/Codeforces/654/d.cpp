#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int grid[1000][1000];
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)  grid[i][j]= 0;
        if(k>=n){
            if(k%n == 0)cout<<0<<endl;
            else cout<<2<<endl;
            for(int i = 0;i<n;i++){
                int cont = 0;
                for(int j = i;cont<k/n;j++,cont++){
                    grid[i][j%n] = 1;
                }
            }

            if(k%n == 0){
                for(int i = 0;i<n;i++){
                    for(int j = 0;j<n;j++){
                        cout<<grid[i][j];
                    }
                    cout<<endl;
                }
            }
            else {
                int cont = 0;
                vector<bool> used(n,false);
                for(int i = 0;cont<k%n;i++){
                    for(int j = 0;j<n;j++){
                        if(grid[i][j]== 0 && !used[j]){grid[i][j] = 1;used[j] =true;cont++;break;}
                    }
                }
                
                for(int i = 0;i<n;i++){
                    for(int j = 0;j<n;j++){
                        cout<<grid[i][j];
                    }
                    cout<<endl;
                }
            }
        }
        else {
            if(k == 0){
                cout<<0<<endl;
                for(int i = 0;i<n;i++){
                    for(int j = 0;j<n;j++){
                        cout<<0;
                    }
                    cout<<endl;
                }
            }
            else{
                cout<<2<<endl;
                for(int i = 0;i<k;i++)
                        grid[i][i] = 1;
                for(int i = 0;i<n;i++){
                    for(int j = 0;j<n;j++){
                        cout<<grid[i][j];
                    }
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}