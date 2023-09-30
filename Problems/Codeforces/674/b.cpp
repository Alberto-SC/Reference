#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,m,a,b,c,d;
    cin>>t;
    while(t--){
        cin>>n>>m;
        bool diagonal = false;
        bool other = false;
        vector<int> grids[n];
        for(int i = 0;i<n;i++){
            cin>>a>>b>>c>>d;
            grids[i].push_back(a);
            grids[i].push_back(b);
            grids[i].push_back(c);
            grids[i].push_back(d);
            if(b ==c)diagonal = true;
        }
        // cout<<diagonal<<endl;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(grids[i][1] == grids[j][2] && grids[i][2]== grids[j][1])other = true;
            }
        }
        if(diagonal && other && m%2 == 0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}

// 5 7 1 5 1 5 1 5
// 7 4 2 6 2 6 2 6
// 1 2 5 7 1 5 1 5
// 5 6 7 4 2 6 2 6
// 1 2 1 2 5 7 1 5
// 5 6 5 6 7 4 2 6
// 1 2 1 2 1 2 5 7 
// 5 6 5 6 5 6 7 4
