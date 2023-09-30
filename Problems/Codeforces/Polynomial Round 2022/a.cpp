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
        int sum = s[0]-'0';
        for(int i = 1;i<n;i++){
            if(s[i]=='1'){
                if(sum == 1)cout<<"-",sum--;
                else cout<<"+",sum++;
            }
            else{
                cout<<"+";
            }
        }
        cout<<endl;
    }
    return 0;
}