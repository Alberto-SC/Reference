#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int main(){__
    int n,x,y,LCM;
    cin>>n;
    vector<int> used(100007,-1);
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        int ans = 0,cont = 0;
        for(int j = 1;j*j<=x;j++){
            if(x%j == 0){
                cont++;
                if(used[j]>=i-y)ans++;
                used[j] = i;
                if(x/j!= j){
                    if(used[x/j]>=i-y)ans++;
                    cont++;
                    used[x/j] = i;
                }
            }
        }
        if(y == 0)cout<<cont<<endl;
        else 
            cout<<cont-ans<<endl;
    }

    return 0;
}