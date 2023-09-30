#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector<int> fx = {-1,-1,+0,+1,+1,+1,+0,-1};
vector<int> fy = {+0,+1,+1,+1,+0,-1,-1,-1};
signed main(){
    vector<vector<int>> M(20,vector<int>(20));
    int ans = 0;
    for(int i = 0;i<20;i++)
        for(int j = 0;j<20;j++)
            cin>>M[i][j];

    for(int i = 0;i<20;i++){
        for(int j = 0;j<20;j++){
            for(int k = 0;k<8;k++){
                bool flag = true;
                int nx = i;
                int ny = j;
                int current = 1;
                for(int l = 0;l<4;l++){
                    if(nx>=20 || ny>=20 || nx<0 || ny<0){
                        flag = false;
                        break;
                    }
                    current*=M[nx][ny];
                    nx+=fx[k];
                    ny+=fy[k];
                }
                if(flag)
                    ans = max(ans,current);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
