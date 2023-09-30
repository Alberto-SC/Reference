#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 14433800;
signed main(){__
	int t= 1,n,x,y,z,b;
    while(t--){
        cin>>b>>n;
        vector<pair<int,int>> B(b);
        for(int i = 0;i<b;i++){
            cin>>B[i].first>>B[i].second;
        }
        const int inf = 1e9;
        vector<int> DP(maxn,inf);
        DP[0] = 0;
        for(int i = 0;i<maxn;i++){
            for(int j = 0;j<b;j++){
                if(i-B[j].first>=0 && DP[i-B[j].first]!=inf){
                    DP[i] = min(DP[i],DP[i-B[j].first]+B[j].second);
                }
            }
        }
        double areaF = 0;
        for(int i = 0;i<n;i++){
            cin>>x>>y>>z;
            double p = (x+y+z)/2.0;
            double area = sqrt(p*(p-x)*(p-y)*(p-z));
            areaF +=area;
        }
        areaF/=30.0;
        int A = (int)ceil(areaF);
        cout<<A<<endl;
        int ans = inf;
        for(int j =A;j<min(maxn,A+100);j++)
            ans = min(ans,DP[j]);
        if(ans== inf)
            cout<<-1<<endl;
        else 
            cout<<ans<<endl;
    }
    return 0;
}  
