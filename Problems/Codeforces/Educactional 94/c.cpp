#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,x;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        cin>>x;
        n =s.size();
        string t(n,'x');
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(s[i]== '0'){
                if(i+x<n)
                    t[i+x] = '0';
                if(i-x>=0)
                    t[i-x] = '0'; 
            }
        }
        for(int i = 0;i<n;i++){
            if(s[i] == '1'){
                bool one = false;
                if(i+x<n && t[i+x] == 'x')t[i+x]='1',one = true;
                if(i-x>=0&& t[i-x] == 'x')t[i-x]='1',one = true;
                if(i+x<n && t[i+x]== '1')one = true;
                if(i-x>=0 && t[i-x]=='1')one = true;
                if(!one)flag = false;
            }
        }
        for(int i = 0;i<n;i++)
            if(t[i]== 'x')t[i] = '1';
        if(flag)cout<<t<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}

