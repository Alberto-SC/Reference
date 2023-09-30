#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> b(7);
map<char,int> mp;

bool check(int start,int end,string s){
    int cont = 0;
    b.assign(7,0);
    for(int i = start;i<=end;i++){
        if(b[mp[s[i]]]){
            return false;
        }
        b[mp[s[i]]] = 1;
        cont++;
        if(cont == 7){
            cont = 0;
            b.assign(7,0);
        }
    }
    return true;
}

signed main(){__
	int t= 1,n;
    cin>>t;
    mp['J'] = 0;
    mp['L'] = 1;
    mp['S'] = 2;
    mp['Z'] = 3;
    mp['I'] = 4;
    mp['O'] = 5;
    mp['T'] = 6;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        bool flag = false;

        if(check(0,n-1,s))flag = true;

        for(int i = 0;i<=min(7ll,n);i++){
            if(check(0,i,s) && check(i+1,n-1,s))flag = true;
        }   
        if(flag)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}  
