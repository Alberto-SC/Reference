#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const int maxn = 57;
int d[maxn][maxn];
void floyd(int n){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);            
            }
        }
    }
}
int main(){
    int t,n;
    cin>>t;
    int cont  = 1;
    while(t--){
        cin>>n;
        vector<bool> I(n);
        vector<bool> O(n);
        for(int i = 0;i<n;i++){
            char c;
            cin>>c;
            if(c== 'N')I[i] = false;
            else I[i] = true;
        }
        for(int i = 0;i<n;i++){
            char c;
            cin>>c;
            if(c== 'N')O[i] = false;
            else O[i] = true;
        }
        char ans[n][n];
        for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)d[i][j] = inf,i==j?ans[i][j]='Y':ans[i][j]= 'N';
        for(int i = 0;i<n;i++)d[i][i]= 1;
        for(int i = 0;i<n;i++){
            if(i-1>= 0){
                if(O[i] && I[i-1])d[i][i-1]= 1;
                if(I[i] && O[i-1])d[i-1][i] = 1;
            }
            if(i+1<n){
                if(O[i] && I[i+1])d[i][i+1] = 1;
                if(I[i] && O[i+1])d[i+1][i] = 1;
            }
        }
        floyd(n);
        
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                if(d[i][j]!= inf)ans[i][j] ='Y';

                
        // for(int i = 0;i<n;i++)
        //     for(int j = 0;j<n;j++)
        //         cout<<d[i][j]<<" \n"[j == n-1];
        
        cout<<"Case #"<<cont<<":"<<endl;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
        cont++;
    }
    return 0;
}
