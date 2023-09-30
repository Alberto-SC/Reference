#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,k;
    while(t--){
        cin>>n>>k;
        vector<int> b[26];
        string s;
        cin>>s;
        for(int i = 0;i<n;){
            int j = i;
            while(j<n && s[i] == s[j]){
                j++;
            }
            b[s[i]-'a'].push_back(j-i);
            i = j;
        }

        int ans =-1;
        for(int i = 0;i<26;i++){
            int sum = 0;
            for(int j = 0;j<b[i].size();j++){
                sum+=b[i][j]/k;
            }
            ans = max(sum,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}

