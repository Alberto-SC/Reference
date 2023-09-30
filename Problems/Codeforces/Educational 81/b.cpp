#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int main(){
    int t,n,x;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>x;
        cin>>s;
        vector<int> prefixes(n);
        int sum = 0;
        int ans = 0;
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(s[i] =='0')sum++;
            else sum--;
            prefixes[i] = sum;
            if(sum == x)flag=true;
        }
        if(x == 0&& n == 1)cout<<1<<endl;
        else if(x == 0&& prefixes[n-1]== 0)cout<<-1<<endl;
        else if(prefixes[n-1]==0){
            if(flag)cout<<-1<<endl;
            else cout<<0<<endl;
        }
        else {
            for(int i = 0;i<n;i++){
                double y = (x-prefixes[i])/(prefixes[n-1]*1.0);
                double y_r = y- trunc(y);
                if(eps> fabs(y_r)&& y>=0)ans++;
            }
            x==0?cout<<ans+1<<endl:cout<<ans<<endl;
        }
    }
    return 0;
}
