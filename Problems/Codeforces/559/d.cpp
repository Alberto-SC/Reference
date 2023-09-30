#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,k;
    while(t--){
        cin>>n>>k;
        int x = (n-k)/2;
        string s(x,'0');
        s.push_back('1');
        for(int i = 0;i<n/(x+1);i++)
            cout<<s;
        if(n%(x+1)){
            for(int i = 0;i<n%(x+1);i++)
                cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}  

