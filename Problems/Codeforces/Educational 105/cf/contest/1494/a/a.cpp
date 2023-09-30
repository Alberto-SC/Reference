#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool check(string a){
    int c = 0;
    for(int i = 0;i<a.size();i++){
        if(a[i]=='(')c++;
        else c--;
        if(c<0)return false;
    }
    return c==0;
}

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        int b = 0;
        bool flag = false;
        for(int i = 0;i<7;i++){
            string aux = s;
            for(int j = 0;j<n;j++){
                if((i>>(s[j]-'A'))&1)
                    aux[j] = '(';
                else 
                    aux[j] =')';
            }
            if(check(aux))flag = true;
            
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
