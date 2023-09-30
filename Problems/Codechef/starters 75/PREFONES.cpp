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
        string s;
        cin>>s;
        
        int mx = 0;
        for(int i = n-1;i>=0;){
            int j = i;
            while(j>=0 && s[i]== s[j]){
                j--;
            }
            if(s[i]== '1' && j>=0){
                mx = max(mx,i-j);
            }
            i = j;
        }

        int f = 0,idx = 0;
        while(s[idx]=='1'){
            idx++;
            f++;
        }
        cout<<f+mx<<endl;
    }
    return 0;
}