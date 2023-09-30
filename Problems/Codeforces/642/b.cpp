#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(i<k && b[i]>a[i])ans+=b[i];
            else ans+=a[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}