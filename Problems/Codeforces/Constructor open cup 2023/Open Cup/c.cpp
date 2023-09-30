#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'


using namespace std;

signed main(){
    int T,n;
    cin>>T;
    while(T--){
        int l,r;
        cin>>n>>l>>r;
        string s;
        cin>>s;
        int a = 0,b = 0;
        for(int i = 0;i<n;i++){
            a+=s[i] == '1';
            b+=s[i] == '2';
        }
        
        bool flag = false;
        int c = n-(a+b);
        for(int i = a;i<=a+c;i++){
            if(n>=(i*l) && n<=(i*r)){
                flag = true;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

