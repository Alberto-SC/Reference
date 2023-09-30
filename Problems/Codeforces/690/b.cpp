#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s,st;
        cin>>s;
        st = "2020";
        int l = 0;
        while(l<n && s[l]== st[l]){
            l++;
        }
        int r = n-1,rt = 3;
        while(r>=l &&rt>=l &&  s[r] == st[rt]){
            r--;
            rt--;
        }
        // cout<<l<<" "<<rt<<" "<<r<<endl;
        if(l == rt+1)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  

