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
        string s;
        cin>>s;
        int idx = n-1;
        while(idx>=0 && s[idx]== ')'){idx--;}
        if(n-(idx+1)>idx+1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}  

