#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

string s;
int ans = 0;
void solve(int idx,string num = ""){
    if(idx==4){
        // cout<<num<<endl;
        for(int i = 0;i<4;i++){
            if(s[num[i]-'0']=='x')return;
        }
        for(int i = 0;i<10;i++){
            bool f = false;
            if(s[i]=='o'){
                for(int j = 0;j<4;j++){
                    if((num[j]-'0')==i)f = true;
                }
            }
            else f = true;
            if(!f)return;
        }
        ans++;
        return;
    }
    for(int i = 0;i<10;i++){
        solve(idx+1,num+to_string(i));
    }
}

signed main(){__
	int t= 1,n;
    cin>>s;
    solve(0);
    cout<<ans<<endl;
    return 0;
}  
