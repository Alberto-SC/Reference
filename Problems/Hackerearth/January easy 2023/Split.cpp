#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;

        set<int> s1,s2;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(a[i] != b[i]){
                if(s2.count(a[i])){
                    s2.erase(a[i]);
                }
                else s1.insert(a[i]);

                if(s1.count(b[i])){
                    s1.erase(b[i]);
                }
                else s2.insert(b[i]);

                if(s1.size()== 0 && s2.size()==0){
                    ans++;
                }
            }
            else{
                if(s1.size()==0 && s2.size()==0){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}