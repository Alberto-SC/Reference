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
        string s,t;
        cin>>s>>t;
        map<char,int> mp1;
        map<char,int> mp2;
        for(int i = 0;i<n;i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        if(mp1['a']!=mp2['a'] || mp1['b']!=mp2['b'] ||mp1['c']!=mp2['c']){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag = true;
        int j = 0;
        for(int i = 0;i<n;i++){
            if(s[i]== 'b')continue;
            while(t[j]== 'b')j++;
            if( s[i] != t[j] || (s[i]== 'a' && i>j) || (s[i]=='c' && i<j)){
                flag = false;
                break;
            }
            j++;
        }
        if(flag )cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}