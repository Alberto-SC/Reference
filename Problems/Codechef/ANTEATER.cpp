#include <bits/stdc++.h>
using namespace std;
#define print(a)for(auto c:a)cout<<c<<" ";
#define ptinm(a)for(auto c:a){ptint(c);cout<<"\n";}
int main(){
    int t,c,r;
    char move;
    cin>>t;
    while(t--){
        cin>>r>>c;
        char matrix[r][c];
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                cin>>matrix[i][j];
            }
        }
        printm(matrix);

    }
    return 0;
}