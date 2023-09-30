#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main(){
    int n;
    cin>>n;
    vector<ld> p(n);
    for(auto &c:p)cin>>c;
    sort(p.rbegin(),p.rend());
    ld ans = 0.0;
    for(int i = 0;i<n;i++){
        ld pb = 0;
        for(int j = 0;j<=i;j++){
            ld win=1.0;
            for(int k = 0;k<=i;k++){
                if(k ==j)win*=p[k];
                else win*=1-p[k];
            }
            pb+=win;
        }
        ans = max(ans,pb);
    }
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
    return 0;
}