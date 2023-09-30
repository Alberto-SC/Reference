#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        string s;
        cin>>s;
        n = a+b;
        for(int i =0;i<n;i++){
            if(s[i]== '0')a--;
            else if(s[i]=='1') b--;
        }
        bool flag = true;
        for(int i = 0;i<n/2;i++){
            if(s[i]== s[(n-i)-1] && s[i]!= '?')continue;
            if(s[i]== '0' && s[(n-i)-1]== '1'){flag = false;break;}
            if(s[i]== '0' && s[(n-i)-1]== '?')s[(n-i)-1] = '0',a--;
            if(s[i]== '1' && s[(n-i)-1]== '0'){flag = false;break;}
            if(s[i]== '1' && s[(n-i)-1]== '?')s[(n-i)-1] = '1',b--;
            if(s[i]== '?' && s[(n-i)-1]== '0')s[i] = '0',a--;
            if(s[i]== '?' && s[(n-i)-1]== '1')s[i] = '1',b--;
        }
        // cout<<a<<" "<<b<<" "<<s<<endl;
        for(int i = 0;i<n/2;i++){
            if(s[i]== '?' && s[(n-i)-1]== '?'){
                if(a>b){
                    s[i]='0';
                    s[(n-i)-1]= '0';
                    a-=2;
                }
                else{
                    s[i] ='1';
                    s[(n-i)-1]= '1';
                    b-=2;
                } 
            }
        }
        if(s[n/2]== '?'){
            if(a>0)s[n/2]='0',a--;
            else if(b>0)s[n/2] = '1',b--;
        }
        // cout<<a<<" "<<b<<" "<<s<<endl;
        if(a!= 0 || b!= 0)flag = false;
        if(flag){
            cout<<s<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}  
