#include<bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

typedef long long int ll;

int T,N,K,s,p,v;

int DP[10007][107];
vector<pair<int,int>> days;

ll dp(int day, ll work){
    if(work<=0)work = 0;
    if(DP[day][work]!= -1)
        return DP[day][work];
    return DP[day][work] = max( days[day].second+ dp(day+1, work), dp(day+1, work-days[day].first));
}


int main(){__
    cin>>T;
    while(T--){
        cin>>N>>K;
        int verify=0;
        days.resize(0);
        for(int i=0; i<N;i++){
            cin>>s>>p>>v;
            verify+=s;
            days.push_back(make_pair(s,max(v,p)));
        }
        for(int i = 0;i<=N;i++)
            for(int j = 0;j<=K;j++)
                DP[i][j] = -1;
        for(int i = 1;i<=K;i++)
            DP[N][i]= INT_MIN;
        DP[N][0] = 0;
        if(verify<K){
            cout<<"NO SOLUTION\n";
        }else{
            // cout<<"llego\n";
            cout<<dp(0,K)<<endl;
        }

    }
    return 0;
}
