#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
    int T = 1,n;
    string s;
    cin>>s;
    n = s.size();
    vector<int> a(10);
    for(int i = 1;i<=9;i++)
        cin>>a[i];
    vector<int> f(10);
    vector<int> pos[10];
    for(int i = 0;i<n;i++){
        f[s[i]-'0']++;
        pos[s[i]-'0'].push_back(i);
    }
    int N = 0;
    for(int i = 0;i<10;i++){
        f[i]-=a[i];
        N +=f[i];
    }

    vector<vector<int>> X(n+1,vector<int>(10));
    for(int i = n-1;i>=0;i--){
        X[i] = X[i+1];
        X[i][s[i]-'0']++;
    }
    string ans ="";
    int last = 0;
    for(int i = 0;i<10;i++)
        reverse(pos[i].begin(),pos[i].end());
    
    while(ans.size()!=N){
        for(int i = 9;i>=0;i--){
            if(!f[i])continue;
            while(pos[i].size() && pos[i].back()<last){
                pos[i].pop_back();
            }
            int id = pos[i].back();
            bool flag = true;
            for(int j = 0;j<=9;j++){
                if(X[id][j]<f[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans +=char(i+'0');
                last = id+1;
                f[i]--;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}