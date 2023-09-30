#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;
int cont[10][10];
signed main(){__
    int n;
    string s;
    cin>>s;
    n = s.size();
    vector<int> a(10);
    iota(a.begin(),a.end(),0);
    for(int i=0;i<n-1;i++)cont[s[i]-'0'][s[i+1]-'0']++;
    int ans = 1e17;
    vector<int> pos(10);
    do{
        for(int i = 1;i<=9;i++)pos[a[i]] = i;
        int res = n;
        res+=abs(pos[s[0]-'0']-pos[a[1]]);
        for(int i = 1;i<=9;i++)
            for(int j = 1;j<=9;j++)
                res+=abs(pos[i]-pos[j])*cont[i][j];
        ans = min(ans,res);
    }while(next_permutation(a.begin()+1,a.end()));
    cout<<ans<<endl;
    return  0;
}