#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> times(n);
        vector<int> low(n);
        vector<int> high(n);
        for(int i = 0;i<n;i++){
            cin>>times[i];
            cin>>low[i];
            cin>>high[i];
        }
        int mn,mx,t0 = 0;
        mn = mx = m;
        bool flag = true;
        for(int i = 0;i<n;i++){
            mx+=times[i]-t0:
            mn-=times[i]-t0;
            if(mx < low[i] || mn > high[i])flag = false;
            mx = min(mx,high[i]);
            mn = max(mn,low[i]);
            t0 = times[i]; P
        }
        flag?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
    return 0;
}
