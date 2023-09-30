#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int f(int x){
    string s = to_string(x);
    return s.size();
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        map<int,vector<int>> pos1;
        map<int,vector<int>> pos2;
        int ans = 0;
        for(int i = 0;i<n;i++){
            pos1[a[i]].push_back(i);
            pos2[b[i]].push_back(i);
        } 
        vector<int> used1(n);
        vector<int> used2(n);
        for(auto c:pos1){
            for(int i = 0;i<min(c.second.size(),pos2[c.first].size());i++){
                used1[c.second[i]] = true;
                used2[pos2[c.first][i]] = true;
            }
        }
        vector<int> f2(10);
        vector<int> f1(10);
        for(int i = 0;i<n;i++){
            if(!used1[i] && a[i]>=10){
                f1[f(a[i])]++;
                ans++;
            }
            else if(!used1[i])f1[a[i]]++;
            
            if(!used2[i] && b[i]>=10){
                f2[f(b[i])]++;
                ans++;
            }
            else if(!used2[i])f2[b[i]]++;
        }
        for(int i= 2;i<=9;i++){
            ans +=max(f1[i],f2[i])-min(f1[i],f2[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}