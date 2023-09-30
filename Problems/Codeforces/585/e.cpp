#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int n,x;
    cin>>n;
    vector<int> idx[20];
    for(int i = 0;i<n;i++){
        cin>>x;
        x--;
        idx[x].push_back(i);
    }
    vector<vector<int>> cont(20,vector<int> (20));
    for(int i = 0;i<20;i++){
        for(int j = 0;j<20;j++){
            if(i == j)continue;
            int id0 = 0,id1 = 0;
            if(idx[i].size()==0 || idx[j].size()==0)continue;
            while(id0<idx[i].size()){
                while(id1<idx[j].size()){  
                    if(idx[j][id1]>idx[i][id0])break; 
                    id1++;
                }
                if(id1-1>=0 && idx[i][id0]>idx[j][id1-1])
                    cont[i][j]+=id1;
                id0++;
            }
        }
    }
    const int inf = 1e16;
    vector<int> DP((1<<20),inf);
    DP[0] = 0;
    for(int i = 0;i<(1<<20);i++){
        vector<int> put;
        for(int j = 0;j<20;j++)
            if((i>>j)&1)
                put.push_back(j);
            

        for(int j = 0;j<20;j++){
            if((i>>j)&1)continue;
            int total = 0;
            for(int k = 0;k<put.size();k++)
                total+= cont[put[k]][j];
            
            int nmask = i|(1<<j);
            DP[nmask] = min(DP[nmask],DP[i]+total);
        }
    }
    cout<<DP[(1<<20)-1]<<endl;
    return 0;
}  
