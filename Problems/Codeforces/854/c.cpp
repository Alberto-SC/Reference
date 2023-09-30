#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        n = s.size();
        string a = "",b = "";
        

        char odd = '*';
        for(int i = 0;i<n;i++){
            if(s[i]== s[i+1]){
                a+=s[i];
                b+=s[i+1];
                i++;
            }
            else{
                if(odd !='*'){
                    a+=s[i];
                    b+=odd;
                    odd = '*';
                }
                else{
                    odd = s[i];
                }
            }
        }
        if(odd != '*')a+=odd;
        reverse(b.begin(),b.end());
        a+=b;

        string a2 = "",b2 = "";
        
        odd = '*';
        bool first = true,flag = false;
        for(int i = 0;i<n;i++){
            if(flag){
                a2+=s[i];
                if(first){
                    b2+=odd;
                    first = false;
                    odd = '*';
                }
            }
            else if(s[i]==s[i+1]){
                a2+=s[i];
                b2+=s[i+1];
                i++;
            }
            else{
                flag = true;
                odd = s[i];
            }
        }
        if(odd!='*')a2 += odd;
        reverse(b2.begin(),b2.end());
        a2+=b2;
        /* cout<<a<<" "<<a2<<endl; */
        cout<<min(a,a2)<<endl;
    }
    return 0;
}

