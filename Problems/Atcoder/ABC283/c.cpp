#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        string s;
        cin>>s;
        n = s.size();
        int ans = 0;
        for(int i = 0;i<n;){
            int j = i;
            while(j<n && s[i]== s[j]){
                j++;
            }   
            if(s[i]== '0'){
                ans +=((j-i)+1)/2;
            }
            else ans+=j-i;
            i = j;
        }
        cout<<ans<<endl;
    }
    return 0;
}