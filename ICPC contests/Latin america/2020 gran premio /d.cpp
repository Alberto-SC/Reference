#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        string s;
        cin>>s>>k;
        string ans;
        int sz = 0;
        n = s.size();
        bool flag = true;
        for(int i = 0;i<n;){
            int l = i;
            int num = 0;
            while(isdigit(s[l])){
                num*=10;
                num+=s[l]-'0';
                l++;
            }
            if(num==0){
                if(sz+1>k){
                    flag = false;
                    break;
                }
                sz++;
                ans+=s[l];
                i++;
            }
            else{
                if(sz+num>k){
                    flag = false;
                    break;
                }
                sz+=num;
                ans+=string(num,s[l]);
                i = l;
                i++;
            }
        }
        if(flag)cout<<ans<<endl;
        else cout<<"unfeasible"<<endl;
    }
    return 0;
}