#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'


using namespace std;

signed main(){
    int T,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        n = s.size();
        int a = 0,b = 0,x = 0,y = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='L')a++;
            else if(s[i]=='R')b++;
            else if(s[i]=='D')x++;
            else y++;
        }
        int ans = abs(a-b)+abs(x-y);
        cout<<ans<<endl;
    }
    return 0;
}

